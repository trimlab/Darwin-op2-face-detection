import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.core.MatOfRect;
import org.opencv.core.Point;
import org.opencv.core.Rect;
import org.opencv.highgui.Highgui;
import org.opencv.objdetect.CascadeClassifier;
import org.opencv.core.Scalar;
import org.opencv.core.Mat;

public class Main {
	//static{ System.loadLibrary("opencv_java2411"); }
    public static void main(String[] args) {
        System.loadLibrary("opencv_java2411");
        //Mat m  = Mat.eye(3, 3, CvType.CV_8UC1);
        //System.out.println("m = " + m.dump());
        
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
        System.out.println("\nRunning FaceDetector");
        System.out.println(Main.class.getResource("data/haarcascade_frontalface_alt.xml").getPath());
        
        CascadeClassifier faceDetector = new CascadeClassifier(Main.class.getResource("data/haarcascade_frontalface_alt.xml").getPath());
        Mat image = Highgui
                .imread(Main.class.getResource("images/face1.jpg").getPath());
 
        MatOfRect faceDetections = new MatOfRect();
        faceDetector.detectMultiScale(image, faceDetections);
 
        System.out.println(String.format("Detected %s faces", faceDetections.toArray().length));
 
        for (Rect rect : faceDetections.toArray()) {
            Core.rectangle(image, new Point(rect.x, rect.y), new Point(rect.x + rect.width, rect.y + rect.height),
                    new Scalar(0, 255, 0));
        }
 
        String filename = "ouput.png";
        System.out.println(String.format("Writing %s", filename));
        Highgui.imwrite(filename, image);
    }
}