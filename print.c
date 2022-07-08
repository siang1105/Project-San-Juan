#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "sanJuan.h"

#define BLACK  "\033[1;0m"
#define RED  "\033[1;31m"
#define BLUE  "\033[1;34m"
#define GREEN  "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define PURPLE  "\033[1;35m"

void introduce(){
    printf(PURPLE);
    printf("|---------------------------------------------------------------------------------|\n");
    printf("|                                                                                 |\n");
    printf("|                          遊戲中玩家們扮演著聖胡安的統治者                       |\n");
    printf("|        指揮著建築師、生產者、商人、議員、礦工等各類人物進行各項活動的經營       |\n");
    printf("|               並可利用其角色所賦予的特權勁量贏的財富和聲望                      |\n");
    printf("|       玩家們在遊戲進行中可建造建築物、生產貨物、銷售貨物、規劃市政及探勘礦場等  |\n");
    printf("|          遊戲在有玩家建造12棟建築後立即結束，由獲得分數最高者成為遊戲贏家       |\n");
    printf("|                                                                                 |\n");
    printf("|---------------------------------------------------------------------------------|\n");
}
void printgame(){
    printf(PURPLE);
    printf("|------------------------------------------------------------------------|\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|                 ");
    printf(YELLOW);
    printf("******        SAN JUAN        ******                   ");
    printf(PURPLE);
    printf("|\n");
    printf("|                                                                        |\n");
    printf("|                              [1] 開始遊戲                              |\n");
    printf("|                              [2] 注意事項                              |\n");
    printf("|                              [3] 遊戲介紹                              |\n");
    printf("|                              [4] 離開                                  |\n");
    printf("|                                                                        |\n");
    printf("|                                           ");
    printf(YELLOW);
    printf("40947007s 張欀齡             ");
    printf(PURPLE);
    printf("|\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|-------------------------------------------------------------------------\n");
    // printf(BLACK);
}

void atten(){
    printf(PURPLE);
    printf("|------------------------------------------------------------------------|\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|                 ");
    printf(YELLOW);
    printf("    1.這是一款 2-4 人的遊戲                            ");
    printf(PURPLE);
    printf("|\n");
    printf("|                     ");
    printf(YELLOW);
    printf("2.使用者永遠都是玩家一(player 1)                   ");
    printf(PURPLE);
    printf("|\n");
    printf("|           ");
    printf(YELLOW);
    printf("  3.所有必須選擇卡牌時，都須按照卡牌前的編號                 ");
    printf(PURPLE);
    printf("|\n");
    printf("|            ");
    printf(YELLOW);
    printf("4.遊戲是在假設使用者完全了解遊戲規則下進行設計              ");   
    printf(PURPLE);
    printf("|\n");                                                       
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|-------------------------------------------------------------------------\n");
}

void printProCard(sproduce *playerCard,sgoods *playerGood){
    // printf("Your Produce Card:\n");
    printf(PURPLE);
    printf("|-------------------------------------\n");
    printf("|");
    printf("你所擁有的生產建築卡:\n");
    printf(BLACK);
    if(playerCard -> indigoPlant != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("1.染料廠 Indigo Plant：%d,已生產貨物：%d\n",playerCard -> indigoPlant, playerGood -> indigoGoods);
    }
    if(playerCard -> sugarMill != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("2.蔗糖廠 Sugar Mill：%d,已生產貨物：%d\n",playerCard -> sugarMill ,playerGood -> sugarGoods);
    }
    if(playerCard -> tobaccoStorage != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("3.菸草廠 Tobacco Storage：%d,已生產貨物：%d\n",playerCard -> tobaccoStorage, playerGood -> tobaccoGoods);
    }
    if(playerCard -> coffeeRoaster != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("4.咖啡廠 Coffee Roaster：%d,已生產貨物：%d\n",playerCard -> coffeeRoaster, playerGood -> coffeeGoods);
    }
    if(playerCard -> silverSmelter != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("5.白銀廠 Silver Smelter：%d,已生產貨物：%d\n",playerCard -> silverSmelter, playerGood -> silverGoods);
    }
    printf(PURPLE);
    printf("|-------------------------------------\n");
    printf(BLACK);
}

void printAllCard(sproduce *playerPro, scard *playerCar){
    printf(PURPLE);
    printf("|---------------------------------------------------------------\n");
    printf("|");
    printf(BLACK);
    printf("你所擁有的卡牌: 第一個數字為擁有該張卡牌的數量\n");
    if(playerPro -> indigoPlant != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("1.染料廠 Indigo Plant：%d (價格：1 ;分數：1)\n",playerPro -> indigoPlant);
    }
    if(playerPro -> sugarMill != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("2.蔗糖廠 Sugar Mill：%d (價格：2 ;分數：1)\n",playerPro -> sugarMill);
    }
    if(playerPro -> tobaccoStorage != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("3.菸草廠 Tobacco Storage：%d (價格：3 ;分數：2)\n",playerPro -> tobaccoStorage);
    }
    if(playerPro -> coffeeRoaster != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("4.咖啡廠 Coffee Roaster：%d (價格：4 ;分數：2)\n",playerPro -> coffeeRoaster);
    }
    if(playerPro -> silverSmelter != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("5.白銀廠 Silver Smelter：%d (價格：5 ;分數：3)\n",playerPro -> silverSmelter);
    }
    if(playerCar -> tower != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("6.塔樓 Tower：%d (價格：3 ;分數：2) <各回合玩家計算手牌前，已打出此張卡牌的玩家手牌上限可增加至12張>\n",playerCar -> tower);
    }
    if(playerCar -> chapel != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("7.禮拜堂 Chapel：%d (價格：3 ;分數：2)\n",playerCar -> chapel);
    }
    if(playerCar -> smithy != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("8.鐵匠鋪 Smithy：%d (價格：1 ;分數：1) <建築師階段時，已打出此張卡牌的玩家在建造生產建築物時可少支付1張手牌>\n",playerCar -> smithy);
    }
    if(playerCar -> poorHouse != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("9.救濟院 Poor House：%d (價格：2 ;分數：1) <建築師階段時，已打出此張卡牌的玩家在行動完成後，若玩家手牌張數不多於1張時，可從卡牌堆抽取1張卡牌加入手牌>\n",playerCar -> poorHouse);
    }
    if(playerCar -> blackMarket != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("10.黑市 Black Market：%d (價格：2 ;分數：1)\n",playerCar -> blackMarket);
    }
    if(playerCar -> crane != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("11.起重機 Crane：%d (價格：2 ;分數：1)\n",playerCar -> crane);
    }
    if(playerCar -> carpenter != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("12.木工場 Carpenter：%d (價格：3 ;分數：2)\n",playerCar -> carpenter);
    }
    if(playerCar -> quarry != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("13.採石場 Quarry：%d (價格：4 ;分數：2) <建築師階段時，已打出此張卡牌的玩家在建造特殊建築物時可少支付1張手牌>\n",playerCar -> quarry);
    }
    if(playerCar -> well != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("14.水井 Well：%d (價格：2 ;分數：1) <生產者階段時，已打出此張卡牌的玩家若生產2個以上貨物，可額外得到一張手牌>\n",playerCar -> well);
    }
    if(playerCar -> aqueduct != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("15.溝渠 Aquedut：%d (價格：3 ;分數：2) <生產者階段時，已打出此張卡牌的玩家可多生產1個貨物>\n",playerCar -> aqueduct);
    }
    if(playerCar -> marketStand != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("16.攤販 Market Stand：%d (價格：2 ;分數：1)\n",playerCar -> marketStand);
    }
    if(playerCar -> marketHall != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("17.市場 Market Hall：%d (價格：4 ;分數：2) <商人階段時，已打出此張卡牌的玩家在行動完成後，可額外得到1張手牌>\n",playerCar -> marketHall);
    }
    if(playerCar -> tradingPost != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("18.交易所 Trading Post：%d (價格：2 ;分數：1)\n",playerCar -> tradingPost);
    }
    if(playerCar -> archive != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("19.檔案館 Archive：%d (價格：1 ;分數：1)\n",playerCar -> archive);
    }
    if(playerCar -> prefecture != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("20.辦公處 Prefecture：%d (價格：3 ;分數：2)\n",playerCar -> prefecture);
    }
    if(playerCar -> goldMine != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("21.金礦坑 Gold Mine：%d (價格：1 ;分數：1)\n",playerCar -> goldMine);
    }
    if(playerCar -> library != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("22.圖書館 Library：%d (價格：5 ;分數：3)\n",playerCar -> library);
    }
    if(playerCar -> statue != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("23.雕鑄像紀念碑 Statue：%d (價格：3 ;分數：3)\n",playerCar -> statue);
    }
    if(playerCar -> victoryColumn != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("24.勝利柱紀念碑 Victory Column：%d (價格：4 ;分數：4)\n",playerCar -> victoryColumn);
    }
    if(playerCar -> hero != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("25.英雄像紀念碑 Hero：%d (價格：5 ;分數：5)\n",playerCar -> hero);
    }
    if(playerCar -> guildHall != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("26.同業會館 Guild Hall：%d (價格：6) <遊戲結束時，已打出此張卡牌的玩家每擁有1棟生產建築物可額外獲得2分>\n",playerCar -> guildHall);
    }
    if(playerCar -> cityHall != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("27.市政廳 City Hall：%d (價格：6) <遊戲結束時，已打出此張卡牌的玩家每擁有1棟特殊建築物(包括此張卡牌)可額外獲得1分>\n",playerCar -> cityHall);
    }
    if(playerCar -> trinmhalArch != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("28.凱旋門 Trinmhal Arch：%d (價格：6) <遊戲結束時，已打出此張卡牌的玩家若擁有1種紀念碑卡可獲得4分，擁有2種可獲得6分，擁有3種可獲得8分>\n",playerCar -> trinmhalArch);
    }
    if(playerCar -> palace != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("29.宮殿 Palace %d：(價格：6 ;分數：1)|遊戲結束時，已打出此張卡牌的玩家可額外獲得該玩家總分的四分之一分數\n",playerCar -> palace);
    }
    printf(PURPLE);
    printf("|---------------------------------------------------------------\n");
    printf(BLACK);
}

void printAllGoods(sgoods *playerGoods){
    printf(PURPLE);
    printf("|---------------------------------------------------------------\n");
    printf("|");
    printf(BLACK);
    printf("你所擁有的貨物：\n");
    if(playerGoods -> indigoGoods != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("1.染料 Indigo Plant Good：%d\n",playerGoods -> indigoGoods);
    }
    if(playerGoods -> sugarGoods != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("2.蔗糖 Sugar Mill Good：%d\n",playerGoods -> sugarGoods);
    }
    if(playerGoods -> tobaccoGoods != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("3.菸草 Tobacco Storage Good：%d\n",playerGoods -> tobaccoGoods);
    }
    if(playerGoods -> coffeeGoods != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("4.咖啡 Coffee Roaster Good：%d\n",playerGoods -> coffeeGoods);
    }
    if(playerGoods -> silverGoods != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("5.白銀 Silver Smelter Good：%d\n",playerGoods -> silverGoods);
    }
    printf(PURPLE);
    printf("|---------------------------------------------------------------\n");
    printf(BLACK);
}

void printJod(sjob *allJob){
    printf("\n");
    printf("輪到你選擇職業\n");
    printf("請選擇以下的職業（須按照職業前的編號輸入）\n");
    if(allJob -> producer != 0){
        printf("1.Producer 生產者  <行動：生產一個貨物//特權：可生產兩個貨物>\n");
    }
    if(allJob -> builder != 0){
        printf("2.Builder 建築師   <行動：可建造一個建築物並支付其費用//特權：可建造一個建築物並支付其費用，但可減少支付一張手牌>\n");
    }
    if(allJob -> prospector != 0){
        printf("3.Prospector 礦工  <行動：無//特權：可抽一張卡牌>\n");
    }
    if(allJob -> trader != 0){
        printf("4.Trader 商人      <行動：可賣出一個貨物//特權：可賣出兩個貨物>\n");
    }
    if(allJob -> councillor != 0){
        printf("5.Councillor 議員  <行動：抽兩張選一張留下//特權：抽五張選一張留下>\n");
    }
    printf("\n");
}

void printBuildedProCard(sbuilded * playerBui,sgoods *playerGood){
    printf(PURPLE);
    printf("|---------------------------------------------------------------\n");
    printf("|");
    printf(BLACK);
    printf("你已建造的生產建築:\n");
    if(playerBui -> indigoPlant != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("1.染料廠 Indigi Plant：%d,已生產貨物：%d\n",playerBui -> indigoPlant, playerGood -> indigoGoods);
    }
    if(playerBui -> sugarMill != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("2.蔗糖廠 Sugar Mill：%d,已生產貨物：%d\n",playerBui -> sugarMill, playerGood -> sugarGoods);
    }
    if(playerBui -> tobaccoStorage != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("3.菸草廠 Tobacco Storage：%d,已生產貨物：%d\n",playerBui -> tobaccoStorage, playerGood -> tobaccoGoods);
    }
    if(playerBui -> coffeeRoaster != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("4.咖啡廠 Coffee Roaster：%d,已生產貨物：%d\n",playerBui -> coffeeRoaster, playerGood -> coffeeGoods);
    }
    if(playerBui -> silverSmelter != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("5.白銀廠 Silver Smelter：%d,已生產貨物：%d\n",playerBui -> silverSmelter, playerGood -> silverGoods);
    }
    printf(PURPLE);
    printf("|---------------------------------------------------------------\n");
    printf(BLACK);
}

void printBuildedCard(sbuilded * playerBui){
    printf(PURPLE);
    printf("|---------------------------------------------------------------\n");
    printf("|");
    printf(BLACK);
    printf("你已建造的建築:\n");
    if(playerBui -> indigoPlant != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("1.染料廠 Indigi Plant：%d\n",playerBui -> indigoPlant);
    }
    if(playerBui -> sugarMill != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("2.蔗糖廠 Sugar Mill：%d\n",playerBui -> sugarMill);
    }
    if(playerBui -> tobaccoStorage != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("3.菸草廠 Tobacco Storage：%d\n",playerBui -> tobaccoStorage);
    }
    if(playerBui -> coffeeRoaster != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("4.咖啡廠 Coffee Roaster：%d\n",playerBui -> coffeeRoaster);
    }
    if(playerBui -> silverSmelter != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("5.白銀廠 Silver Smelter：%d\n",playerBui -> silverSmelter);
    }
    if(playerBui -> tower != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("6.塔樓 Tower：%d|各回合玩家計算手牌前，已打出此張卡牌的玩家手牌上限可增加至12張\n",playerBui -> tower);
    }
    if(playerBui -> chapel != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("7.禮拜堂 Chapel：%d\n",playerBui -> chapel);
    }
    if(playerBui -> smithy != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("8.鐵匠鋪 Smithy：%d|建築師階段時，已打出此張卡牌的玩家在建造生產建築物時可少支付1張手牌\n",playerBui -> smithy);
    }
    if(playerBui -> poorHouse != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("9.救濟院 Poor House：%d|建築師階段時，已打出此張卡牌的玩家在行動完成後，若玩家手牌張數不多於1張時，可從卡牌堆抽取1張卡牌加入手牌\n",playerBui -> poorHouse);
    }
    if(playerBui -> blackMarket != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("10.黑市 Black Market：%d\n",playerBui -> blackMarket);
    }
    if(playerBui -> crane != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("11.起重機 Crane：%d\n",playerBui -> crane);
    }
    if(playerBui -> carpenter != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("12.木工場 Carpenter：%d\n",playerBui -> carpenter);
    }
    if(playerBui -> quarry != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("13.採石場 Quarry：%d|建築師階段時，已打出此張卡牌的玩家在建造特殊建築物時可少支付1張手牌\n",playerBui -> quarry);
    }
    if(playerBui -> well != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("14.水井 Well：%d|生產者階段時，已打出此張卡牌的玩家若生產2個以上貨物，可額外得到一張手牌\n",playerBui -> well);
    }
    if(playerBui -> aqueduct != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("15.溝渠 Aqueduct：%d|生產者階段時，已打出此張卡牌的玩家可多生產1個貨物\n",playerBui -> aqueduct);
    }
    if(playerBui -> marketStand != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("16.攤販 Market Stand：%d\n",playerBui -> marketStand);
    }
    if(playerBui -> marketHall != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("17.市場 Market Hall：%d|商人階段時，已打出此張卡牌的玩家在行動完成後，可額外得到1張手牌\n",playerBui -> marketHall);
    }
    if(playerBui -> tradingPost != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("18.交易所 Trading Post：%d\n",playerBui -> tradingPost);
    }
    if(playerBui -> archive != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("19.檔案館 Archive：%d\n",playerBui -> archive);
    }
    if(playerBui -> prefecture != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("20.辦公處 prefecture：%d\n",playerBui -> prefecture);
    }
    if(playerBui -> goldMine != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("21.金礦坑 GoldMine：%d\n",playerBui -> goldMine);
    }
    if(playerBui -> library != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("22.圖書館 Library：%d\n",playerBui -> library);
    }
    if(playerBui -> statue != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("23.雕鑄像紀念碑 Statue：%d\n",playerBui -> statue);
    }
    if(playerBui -> victoryColumn != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("24.勝利柱紀念碑 Victory Column：%d\n",playerBui -> victoryColumn);
    }
    if(playerBui -> hero != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("25.英雄像紀念碑 Hero：%d\n",playerBui -> hero);
    }
    if(playerBui -> guildHall != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("26.同業會館 Guild Hall：%d|遊戲結束時，已打出此張卡牌的玩家每擁有1棟生產建築物可額外獲得2分\n",playerBui -> guildHall);
    }
    if(playerBui -> cityHall != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("27.市政廳 City Hall：%d|遊戲結束時，已打出此張卡牌的玩家每擁有1棟特殊建築物(包括此張卡牌)可額外獲得1分\n",playerBui -> cityHall);
    }
    if(playerBui -> trinmhalArch != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("28.凱旋門 Trinmhal Arch：%d|遊戲結束時，已打出此張卡牌的玩家若擁有1種紀念碑卡可獲得4分，擁有2種可獲得6分，擁有3種可獲得8分\n",playerBui -> trinmhalArch);
    }
    if(playerBui -> palace != 0){
        printf(PURPLE);
        printf("|");
        printf(BLACK);
        printf("29.宮殿 Palace：%d|遊戲結束時，已打出此張卡牌的玩家可額外獲得該玩家總分的四分之一分數\n",playerBui -> palace);
    }
    printf(PURPLE);
    printf("|---------------------------------------------------------------\n");
    printf(BLACK);
}

