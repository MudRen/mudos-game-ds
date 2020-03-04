#include <ansi.h>
inherit ITEM;


void create()
{
        set_name(HIY"煙"NOR""YEL"火"NOR, ({ "firework" }) );
        set("long", @LONG
        
這是一個煙火, 點燃它(fire_firework), 你將會獲得許多樂趣。

用法：fire_firework <字句>
LONG);
  if(clonep() )
    set_default_object(__FILE__);
    else
    {
    set("base_unit", "個");
    set("value", 1500);
    set("base_value", 1000);
    set("base_weight", 100);
    set("needsc", 1000);
                set("unit", "個");
                }
        setup();
} 

void init()
{
        add_action("do_light","fire_firework");
}


int do_light(string s)
{
        string s1, s2, cmsg;

        switch (random(7))
        {
        case 0  : s1= HIR; s2= "紅"; break;
        case 1  : s1= HIM; s2= "紫"; break;
        case 2  : s1= HIY; s2= "黃"; break;
        case 3  : s1= HIG; s2= "綠"; break;
        case 4  : s1= HIB; s2= "藍"; break;
        case 5  : s1= HIC; s2= "青"; break;
        case 6  : s1= HIW; s2= "白"; break;
        default : s1= HIR; s2= "紅";
        } 

        message_vision("$N將煙火點著, 然後掩住耳朵迅速地躲到一邊。\n",
                this_player() );
        if (!s) cmsg = s1 + "\n\t砰！的一聲，一枚美麗的"+ s2 +
                "色煙火在天空中迸射開來。\n" + NOR;
        else cmsg = s1 + "\n\t砰！的一聲，許\多枚美麗的"+ s2 +
                "色煙火在空中迸射開來，緩緩幻化成一排字：\n\n\t"+s+"。\n\n" + NOR;
        shout(cmsg);
        write(cmsg);
        CHANNEL_D->do_channel(this_player(), "sys","施放了煙火。\n");
        destruct(this_object());

        return 1;
} 

