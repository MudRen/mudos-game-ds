#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(MAG"死神祝福"NOR ,({ "Dead-God Bless ring","ring" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long",@LONG
這是傳說中死神敗給遊龍俠時, 因感祂不殺之恩所送之祝福!
LONG
     );
                set("unit", "件");
                set("value",99999);
                set("material", "silver");
                set("armor_prop/int",20);
                set("armor_prop/str",20); 
                set("wear_msg", MAG"$N拿出$n往手上一戴, 一股陰森森的感覺浮上心頭...\n"NOR); 
                set("armor_prop/id",({"dead god","god"}));
                set("armor_prop/name",({"死神"}));
                set("armor_prop/short",({"死神(dead god)"}));
                set("armor_prop/long",({"
                          ▃▅▇██▇▅▃
                        ▇████████▇
                       ███████████
         ▄          ██▄███████▄██
         ▍         ███      ██     ███
         █        ▌█         █         ██
         ▄         █                       █
      ▄ ▄ ▄ ▃  █                       █
      ▌ ▌ ▌ ▅   █          █          █
   ▄█▌█ █ ▌   █▄     █  █     ▄█
  █▄▄▄▄▄▄▄   ▃ █▄█      █▄█ ▃
 █ █ █ █ █ █    █▄██      █▌▄█
  ▌███████      █ ██    ▌▌ █
 █ ██████        █  ▌▌▅ ▌▌ █
    ████▃▌        █            █
      █▃ ██           █ ▌▌ ▌▌█
      ██ ██              ████


"}) );
                      }
        setup();
}

