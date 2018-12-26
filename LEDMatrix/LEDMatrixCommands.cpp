#include "LEDMatrixCommands.h"
#include "LEDMatrix.h"

void usblog(String str) {
  Serial.println(str);
}

void setupCommandRouter(RegexKeyFunctionMap &Router) {

    /// 大家要在這裡完成各種功能！！！
    /// *************** setup command here!!!! ***************
    // exaple:
    // Router.map(正則表達式, [](std::vector<std::string> matches) {
    //   matches[0]; //  整格字串
    //   matches[1]; // 第一組 re group
    //   matches[2]; // 第二組 re group, and so on
    // });

    // !bounce "This Text Should be bouncing"
    Router.map("^[!](bounce|bouncetext)[ ](.*)$", [](std::vector<String> matches) {
      // c_str for Arduino string compatability
      usblog("Bouncing text: "+matches[2]);
      // return 0;
    });

    Router.map("^[^!](.*)$", [](std::vector<String> matches) {
      usblog("Plain text: "+matches[0]);
      // return 0;
    });

    Router.map("^(.*)[.](.*)$", [](std::vector<String> matches) {
      usblog("Dot text(full): "+matches[0]);
      usblog("Dot text(int): "+matches[1]);
      usblog("Dot text(float): "+matches[2]);

      // return 0;
    });

    /// *************** setup command end ********************
}