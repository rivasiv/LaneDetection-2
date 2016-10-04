#include "main.h"
#include "img_processing.h"

int main(int argc, char** args){

	// assertions
	assert((VIDEO + CAMERA + STATIC_IMAGE) == 1 && "Only one type of input should be enable at a time");
	init(argc,args);

	char c = 'a';
	Mat img;
	while(c != 27){
#if STATIC_IMAGE
		if(!(ent = readdir (dir)))
			break;
		img = readImage(ent->d_name);
		if(!img.empty()) // check if file is directory or not image
			imshow(ent->d_name, img);
#elif VIDEO || CAMERA
		img = readImage(capture);
		if(img.empty())
			break;
		imshow("Preview", img);
#endif
		if(!img.empty()){
			Mat output = imgProcessing(img);
			imshow("OUTPUT", output);
		}
		c = waitKey(WAIT_TIME);
	}
	exit();
}

