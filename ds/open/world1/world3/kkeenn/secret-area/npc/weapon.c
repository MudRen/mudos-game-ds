#include <ansi.h>
inherit ITEM;
inherit SELLMAN;

void create()
{
       set_name(HIY"�Z������"NOR, ({ "weapon selling machine","machine"}));
        set("long","�o�O�@������,�i�H��list�h�ݬݦ�����F�F��C\n");
        set("sell_list",([
"/open/world3/super-light-area/weapon/wp/cannon.c" : 2,
"/open/world3/super-light-area/weapon/wp/anesthetize.c" : 2,
"/open/world3/super-light-area/weapon/wp/mag.c" : 2,
"/open/world3/super-light-area/weapon/wp/pistol.c" : 2,
"/open/world3/super-light-area/weapon/wp/tranquilizer.c" : 2,
"/open/world3/super-light-area/weapon/wp/anesthetize_clip.c" : 2, 
"/open/world3/super-light-area/weapon/wp/cannon_clip.c" : 2, 
"/open/world3/super-light-area/weapon/wp/mag_clip.c" : 2, 
"/open/world3/super-light-area/weapon/wp/pistol_clip.c" : 2, 
__DIR__"obj/sword.c" : 10,
        ]) );
set_weight(99999);
                set("no_get",1);
                set("no_sac",1);
        setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}


