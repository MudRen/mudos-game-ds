#include <ansi2.h>
inherit ITEM;

#define BOSS "/open/world1/tmr/blood_field2/npc/nightbane.c"
#define TREEBREAD "/open/world1/tmr/blood_field2/npc/ents3.c"

void create()
{
    set_name(HBK"夜禍烏石"NOR, ({"nightbane dark-stone", "dark-stone", "stone", "_NIGHTBANE_STONE_"}));
    if( !clonep() ) {
        set("long", @LONG
這是一顆黑漆漆的石頭，拿著手上就有股不詳之感。
LONG
                );
        set("value", 10);
        set("unit", "粒");
        set("weight", 10);
        set("value",10);
        } else
                   set_default_object(__FILE__);
    setup();
}

void init()
{
  add_action("do_crumb","crumb");
}

int do_crumb(string arg) {
        
        object ob;
        if(!arg || arg != "stone")
                return notify_fail("你想要捏碎什麼？\n");
        
        if( environment(this_player())->query("short") != "骨龍妖霧" )
                return notify_fail("你在這裡似乎捏碎夜禍烏石。\n" );

        ob = find_living("_NIGHTBANE_");        
        if(objectp(ob) && !objectp(environment(ob))) 
                destruct(ob);

        if(objectp(ob) )
                return notify_fail("夜禍已經在附近出沒了。你無法捏碎夜禍烏石。\n" );
        
        message_vision(HBK"$N"HBK"用力捏碎夜禍烏石，竟冒出大量的濃濃黑煙，充斥在整個空間！！\n"NOR, this_player());
        
        ob = new(TREEBREAD);
        ob->move(environment(this_player()));
        ob = new(TREEBREAD);
        ob->move(environment(this_player()));
        ob = new(BOSS);
        ob->move(environment(this_player()));

     message("world:world1:vision",
           HIR"\n\t"+ob->name()+HIG"發出深沉的怒吼：「無知的凡人 "+this_player()->name(1) + "(" + this_player()->query("id") +") ！！納命來吧！！！」\n\n" NOR
        ,users() );
        
        destruct(this_object());        
        return 1;
}


