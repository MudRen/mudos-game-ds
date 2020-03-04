#include <room.h>
inherit ROOM;
void create()
{
        set("short", "MUSIC ROOM");
        set("long", @LONG
這裡就是大家平時假日沒工作時最常到的休息之處，來這裡與親朋好
友、樓上樓下的好鄰居，大家快快樂樂的高歌一曲，準備迎接明天的工作
。旁邊乘涼的大機械傘上掛著一本小冊子( List )好像是登記歌曲編號用
的，點唱機就在旁邊( 指令: singing 編號 )。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "up":__DIR__"sec5.c",
     
]));
        set("item_desc", ([
        "list" :"
====================[33m曲[0m                    [33m目[0m======================== 
一、 溫柔
二、 超快感
三、 Don't say you love me 別說妳愛我
四、 你愛我嗎(愛在心裡蔓延版)
五、 患得患失
六、 我會想妳
七、 是你變了嗎？
八、 朋友
九、 一擊即中
十、 一了百了
十一、 別來無恙
十二、 I love you 無望
十三、 屋頂
十四、 小姐 這是我的名片
十五、 三瞑三日
十六、 留心
十七、 很愛很愛你
十八、 FIRST Love
十九、 LIGHT THE LIGHT (American Edition)
二十、 約定
二十一、 單眼皮女生
二十二、 分享
二十三、 口香糖
二十四、 愛的代價
二十五、 想愛
二十六、 少ㄌ你我該怎麼辦
二十七、 風箏 
二十八、 綠光
二十九、 是嗎
三十、 一個人的精彩
三十一、 天天開心

[36m(點歌用singing 編號 [for 人])[0m
============================Update By Kkeenn@DS 2001/12/30==================
/n",
        ]));

        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/singer.c"   :1,
]));

        setup();
        replace_program(ROOM);

}
