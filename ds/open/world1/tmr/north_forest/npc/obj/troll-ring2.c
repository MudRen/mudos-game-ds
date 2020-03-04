#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name( "森金之戒" ,({"troll ring","ring"}));
  if( clonep() ) set_default_object(__FILE__);
  else
  {
    set("long",@LONG
森金是暗矛巨魔一族中的歷史英雄，在約二百年前，森金率領
暗矛部落在大漩渦附近的島嶼定居，平和的時光沒能持續多久。來
自庫爾提拉斯的人類在此紮營，不斷侵犯。雙方交戰十幾年，由於
有森金的領導，最後終於打敗了人類，也拯救了暗矛部落。森金之
戒也就從在那時被鑄造出來，用來歌頌森金的貢獻。
LONG
);
    set("value",10000); 
    set_weight(1000); 
    set("material","diamond");
    set("unit","只");
  } 
  set("armor_prop/dex", 1);
  set("armor_prop/con", 1);
  set("armor_prop/armor", 5);
  setup();
}

