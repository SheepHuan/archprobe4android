package mobi.eis.archprobe;

public class NativeLib {

    // Used to load the 'archprobe' library on application startup.
    static {
        System.loadLibrary("archprobe");
    }


    public static native void main(String saveDirpath);
}