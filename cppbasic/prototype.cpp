#include <iostream>
using namespace std;
enum imageType{
    LAST,SPOT
};

class Image {
public :
    virtual void draw()=0;
    static  Image *findAndClone(imageType);
protected:
    virtual imageType  returnType()=0;
    virtual Image* clone()=0;
    static void addPrototypes(Image * img){
        _prototypes[_nextSlot++]=img;
    }
private:
    static Image * _prototypes[10];
    static int  _nextSlot;
};
Image *Image::_prototypes[];
int Image::_nextSlot;

Image *Image::findAndClone(imageType type){
    for (int  i = 0; i < _nextSlot; i++)
    {
        if (_prototypes[i]->returnType()== type){
            _prototypes[i]->clone();
        }
        }
    
}
class LandSatImage:public Image{
public :
    imageType returnType(){
        return LAST;
    }
    void draw(){
        cout<<"LandSatImage::draw()"<<_id<<endl;
    }
    Image * clone(){
        return new LandSatImage(1);
    }

protected:
    LandSatImage(int i){
        _id=_count++;
    }
private:
    static int _count;
    int _id;
    static LandSatImage _landsatImage;
    LandSatImage(){
        addPrototypes(this);
    }
}; 
LandSatImage LandSatImage::_landsatImage;
int LandSatImage::_count=1;


class SpotImage:public Image{
public :
    void draw(){
        cout<<"SpotImage::draw()"<<_id<<endl;
    }
    imageType returnType(){
        return SPOT;
    }
    Image * clone(){
        return new SpotImage(1);
    }
protected:
    SpotImage(int i){
        _id=_count++;
    }
private:
    int _id;
    static int _count;
    static SpotImage _spotImage;
    SpotImage(){
        addPrototypes(this);
    }
};
SpotImage SpotImage::_spotImage;
int SpotImage::_count=1;
int main(){
    // Image im;
    // im.draw();
    // LandSatImage ldim;
    // ldim.draw();
    // _landsatImage.draw();
}