#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIB"專屬金人"NOR, ({ "gold's man", "man" }) );
        set("race", "robot");
        set("age", 1);
        set("long", @long
你隱約看到眼前的火團中有一個人,再定睛一看,發現他原來是被一道道的紅蓮之火所包圍著
他緊閉著雙目,口中也喃喃地念著咒文,而一道道的神武真火也從其手上冒出來了
再看著看著..竟然發現火團中還有著數十條火龍隨著真火而冒出了頭來
就像要把你眼前的人吞噬似的.
long);
        set("level",1);
        set("mobhp",300000000000);
        set_temp("apply/dodge",-999);
        set_temp("apply/armor",-10);
        setup();
}
int receive_damage(string type,int damage,object who)
 {
  if( !who ) return 0;
  who->add("exp", 10000000); 

  who->add("popularity",10);  
  who->add("mud_age",10000);
 }

