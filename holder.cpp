#include <windows.h>
#include <iostream>
#include <curl/curl.h>

#define ll long long
#define isPurple (red < 174 && red > 150 && green > 120 && green < 150 && blue > 180 && blue < 220)

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//r 88
//g 101
//b 242


int x[] = {330,394,457};
int y[] = {978,978,978};

int xwish[] = {360,421,483};
int ywish[] = {979,979,979};

int squareCord[] = {326,972};

int messageBar[] = {368, 1046};
int sendButtom[] = {688,1046};

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

void DeviceContextFailMessage(){
    WebhookMessage("HDC FAIL MAX SECUTITY ME AJUDAAA");
    log("MASSIVE FAIL MAX SECURITY PRESS RED BUTTON FAIL FAIL DEVICE CONTEXT FAIL",true);
    WebhookMessage("It got force stopped i think?");
    std::cerr << "Failed to get Device Context." << std::endl;
    log("MASSIVE FAIL MAX SECURITY PRESS RED BUTTON FAIL FAIL DEVICE CONTEXT FAIL",true);
}

void sdropsend(){
    mouseClick(messageBar[0], messageBar[1]);
    typeKey(0x53);
    typeKey(0x44);
    mouseClick(sendButtom[0], sendButtom[1]);
    log("did sd",true);
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
        DeviceContextFailMessage();
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
            WebhookMessage("<@744095326121754683> i found a card above 100 wishlist!!yayyyy");
            break;
        }
    }

    if(dp == false){
        log("clanker didnt find a good card",true);
    }
    

    ReleaseDC(NULL, hdc);
    return dp;
}

void CheckForPauseAndResume(){
    int red = 0;
    int green = 0;
    int blue = 0;

    HDC hdc = GetDC(NULL);

    if (hdc == NULL) {
        DeviceContextFailMessage();
    }
    
    COLORREF color = GetPixel(hdc,squareCord[0],squareCord[1]);

    red   = GetRValue(color);
    green = GetGValue(color);
    blue  = GetBValue(color);

    //169 141 214 purple
    //120 176 89 green 
    if(isPurple){
        WebhookMessage("[sys] Paused with the purple thing..");
        log("Paused with the purple thing..",true);
        while(true){
           Sleep(60*1000);

           COLORREF color = GetPixel(hdc,squareCord[0],squareCord[1]);

           red   = GetRValue(color);
           green = GetGValue(color);
           blue  = GetBValue(color);

           if(!(isPurple)){
              WebhookMessage("[sys] i dont see a purple cube anymore, going back to work, i hate my clanker life.");
              log("Unpaused",true);
              break;
           }
        }
        
    }
    
    ReleaseDC(NULL, hdc);
}

int main(){
    srand(time(__null));

    WebhookMessage("[sys] Starting the thing hi uh im shy");
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

        CheckForPauseAndResume();

        sdropsend();
        Sleep(4000);
        Sleep((rand()%1000)+500);
        if(!try_finding_a_good_card_and_grab()){
            grabRandomCard();
        }
        else{
            temptext = "i got " + to_string(clankerbrain+1) + " cards above 100 wl";
            WebhookMessage(temptext);
            clankerbrain++;
        }

        Sleep(1000);

        Sleep((8*60*1000)+5);

        if(rand() % 160 == 0){
            WebhookMessage("https://klipy.com/gifs/yuyuko-touhou-fumo");
        }
        else if(rand() % 170 == 0){
            WebhookMessage("https://klipy.com/gifs/yuyuko-yuyuko-saigyouji");
        }
        else if(rand() % 170 == 0){
            WebhookMessage("https://cdn.discordapp.com/attachments/845296947182960664/1518274701686734868/togif.gif?ex=6a832701&is=6a81d581&hm=ef33bb9c89ebe00cd42a9cbc6ee30037d3af5ea7bad25cab10b0034d6d21483d&");
        }
        else if(rand() % 190 == 0){
            WebhookMessage("https://klipy.com/gifs/fumo-touhou-6");
        }
        else if(rand() % 200 == 0){
            WebhookMessage("https://cdn.discordapp.com/attachments/1098359555060154428/1215641607156801577/togif-5.gif?ex=6a830278&is=6a81b0f8&hm=65c3742285aa9eb2941746948a0cc61af2a3977a7acdc50ac4152201e80c37e3&");
        }

        sdTimes++;
        cls();
    }

    cout<<"Force Stopped with P!";
    WebhookMessage("stopped with p chan wowwww");
    WebhookMessage("https://tenor.com/view/yuyuko-fumo-cat-hug-snuggle-gif-3441104698059113185");

    return 0;
}
