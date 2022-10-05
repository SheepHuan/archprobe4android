package mobi.eis.archprobe4android;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import java.io.File;
import java.lang.annotation.Native;

import mobi.eis.archprobe.NativeLib;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    }

    Button archprobeButton;

    @Override
    protected void onResume() {
        super.onResume();
        archprobeButton = findViewById(R.id.run_archprobe);
        archprobeButton.setOnClickListener(this);
    }


    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.run_archprobe:
            {
                //创建一个子文件夹archprobe
                File filedir=new File(getFilesDir()+"/"+"archprobe");
                filedir.mkdirs();
//                System.out.println(filedir.getAbsolutePath());
                NativeLib.main(filedir.getAbsolutePath()+File.pathSeparator);
            }
        }
    }
}