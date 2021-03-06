#include <ansi.h>
#include <armor.h>
inherit NECK;
inherit F_UNIQUE;

string *wounds = ({
  "head", 
  "body",
  "right_arm",
  "left_arm",
  "right_leg",
  "left_leg",
});

void create()
{
        set_name(MAG"殞星鏈"NOR,({"star necklace","necklace"}) );
        set("long",@LONG
傳說中在神廟創建完工之時, 忽然一道紫光從地底射出, 
在紫光散去之後, 殞星老者及這條鍊子就同時出現了,可
見這條項鍊頗有來歷.....
LONG
);
        set_weight(30); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_level",30);
                set("unit", "串");
                set("light",1);       
                set("value",1070);          
                set("volume", 4);                       
                set("material", "blacksteel");
                 set("no_put",1);
                 set("no_give",1);   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/str",1);
        set("armor_prop/dex",1);
        set("armor_prop/int",3);
                set("no_sell", 1);
        set("replica_ob", __DIR__"steel_necklace.c");
        setup();
        call_out("receive_by_necklace", 30);
}

void receive_by_necklace()
{
        object me = environment(this_object());
        int p_mp, i;

        if( !this_object() || !me ) return;
        if( interactive(me) && me->query_temp("armor/neck") == this_object())
        {
                p_mp = me->query("max_mp");
                if( me->query("mp") < p_mp )
                {
                        me->receive_heal("mp", p_mp*4/37);
                        for(i=0;i<sizeof(wounds);i++)
                                me->receive_curing(wounds[i], 1);
                        message_vision(HIM"$N傳出一股溫和的氣息, 撫慰$n紊亂的心靈....\n"NOR, this_object(), me);
                }
                else
                {
//                        tell_object("me,殞星鏈傳出一道氣息, 但是沒有什麼事發生！\n");
                        tell_object(me,"殞星鏈傳出一道氣息, 但是沒有什麼事發生！\n");
                }
        }
        call_out("receive_by_necklace", 35);
}
