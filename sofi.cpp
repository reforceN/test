#include <windows.h>
#include <iostream>
#include <curl/curl.h>
#define ll long long

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// message bar: 368 1046
// first heart: 350 975
// second heart: 417 975
// third heart: 476 977

//r 88
//g 101
//b 242


int x[] = {350,417,476};
int y[] = {975,975,977};

int xwish[] = {382,444,504};
int ywish[] = {979,979,979};

int temp = 0;
const string webhook_url = "";


void stc(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

void cls(){
    system("cls");
}


void WebhookMessage(string message){
    CURL* curl = curl_easy_init();

    std::string payload = "{\"content\": \"" + message + "\"}";

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, webhook_url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());

    CURLcode res = curl_easy_perform(curl);

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
}

void typeKey(int vkCode) {
    keybd_event(vkCode, 0, 0, 0);
    keybd_event(vkCode, 0, KEYEVENTF_KEYUP, 0);
}

void mouseClick(int x, int y) {
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}


void log(string text, bool n){
    stc(6); cout<<"[Log] "; stc(7);
    cout<<text;
    if(n) cout<<"\n";
}

void sdropsend(){
    mouseClick(368, 1046);
    typeKey(0x53);
    typeKey(0x44);
    mouseClick(688,1046);
    log("did sd",true);
}

void sayRandomSpeech(){
      mouseClick(368, 1046);
      typeKey(0x43); typeKey(0x41); typeKey(0x47); typeKey(0x4F);
      mouseClick(688,1046);
      log("send random speech",true);
}

void grabCard_arraywise(int n){
    temp = n;
    mouseClick(x[n],y[n]);
    log("did grab card #",false);
    cout<<temp+1<<"\n";
}

void grabRandomCard(){
    temp = (rand()%3);
    grabCard_arraywise(temp);
}

bool try_finding_a_good_card_and_grab(){
    bool dp = false;
    int red = 0;
    int green = 0;
    int blue = 0;

    HDC hdc = GetDC(NULL); 

    if (hdc == NULL) {
        log("MASSIVE FAIL MAX SECURITY PRESS RED BUTTON FAIL FAIL DEVICE CONTEXT FAIL",true);
        std::cerr << "Failed to get Device Context." << std::endl;
        log("MASSIVE FAIL MAX SECURITY PRESS RED BUTTON FAIL FAIL DEVICE CONTEXT FAIL",true);
        return dp;
    }

    for(int i=0; i<=2; ++i){
        COLORREF color = GetPixel(hdc, xwish[i], ywish[i]);

        red   = GetRValue(color);
        green = GetGValue(color);
        blue  = GetBValue(color);

        if(red == 88 && green == 101 && blue == 242){
            grabCard_arraywise(i);
            dp = true;
            log("clanker thinks this card is better",true);
            WebhookMessage("<@813849200831103047> <@744095326121754683> i found a card above 100 wishlist!!yayyyy");
            break;
        }
    }

    if(dp == false){
        log("clanker didnt find a good card",true);
    }
    

    ReleaseDC(NULL, hdc);
    return dp;
}

bool gen_find_and_grab(){
    bool dp = false;
    int red = 0;
    int green = 0;
    int blue = 0;

    HDC hdc = GetDC(NULL); 

    if (hdc == NULL) {
        log("MASSIVE FAIL MAX SECURITY PRESS RED BUTTON FAIL FAIL DEVICE CONTEXT FAIL",true);
        std::cerr << "Failed to get Device Context." << std::endl;
        log("MASSIVE FAIL MAX SECURITY PRESS RED BUTTON FAIL FAIL DEVICE CONTEXT FAIL",true);
        return dp;
    }

    //

    if(dp == false){
        log("clanker didnt find a good card",true);
    }
    

    ReleaseDC(NULL, hdc);
    return dp;
}

int main(){
    srand(time(__null));

    WebhookMessage("Starting the thing hi uh im shy");
    std::cout<<"Starting..\n Please close yasb and open discord halfscreen\n";

    Sleep(7000); //tab in

    std::cout<<"Running..\n";

    int sdTimes = 0;
    int clankerbrain = 0;
    ll t = time(0);
    string temptext = "";

    while(!GetAsyncKeyState('P')){
        cout<<"sd: "; stc(10);
        cout<<sdTimes<<"\n"; stc(7);

        cout<<"catch by clanker: "; stc(10);
        cout<<clankerbrain<<"\n"; stc(7);

        cout<<"time elapsed: "<<time(0)-t<<" seconds, "<<float((time(0)-t)/60.0f)<<" minutes, "<<float(((time(0)-t)/60.0f)/60.0f)<<" hours.\n";

        temptext = "i did sd " + to_string(sdTimes+1) + " times hehehehe";
        WebhookMessage(temptext);

        sdropsend();
        Sleep(7000);
        if(!try_finding_a_good_card_and_grab()){
            grabRandomCard();
        }
        else{
            clankerbrain++;
        }

        Sleep(3000);

        //sayRandomSpeech();

        Sleep((8*60*1000)+5);

        sdTimes++;
        cls();
    }
    cout<<"Force Stopped with P!";


    return 0;
}

