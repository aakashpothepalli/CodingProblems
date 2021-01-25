//this function toggles all the bits of a number
unsigned int flippingBits(unsigned int n) {
    long ans =0;


    for(int i=0;i<32;i++){
        n = n ^ (1<<i);
    }
    return n;

}