inherit ITEM;
#include <ansi.h>
void setup()
{}
void init()
{
        add_action("do_enter", "enter");
}
void create()
{
        set_name(HIB"藍轎"NOR, ({"blue jiao","jiao"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是一頂藍色的轎子，好像是常春霖的坐轎。\n");
                set("unit", "頂");
                set("no_get", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_drop", 1);
                set("no_put", 1);
        }
        setup();
}
int do_enter(string arg)
{
        object room, me = this_player();
        if( !arg || arg!="jiao" ) return 0;
        message_vision(HIR"$N一進到轎裡就想睡覺 . . . 四周景象似乎都沒變，可能是自己睡昏了吧。\n\n"NOR, me ) ; 
        message_vision(HIC"一路上搖搖晃晃 . . . . \n\n"NOR, me ) ;        if( !(room = find_object(__DIR__"jiao")) )
            room = load_object(__DIR__"jiao");
        if( room = find_object(__DIR__"jiao") ) 
        me->move(room);
        message("vision", me->name() + "你看到一個人從外面坐了進來。\n\n",
                environment(me), ({me}) );
        call_out("reach", 20, me);
        return 1;
}       

void reach(object me)
{
        tell_object(me, "轎子突然頓了一下 . . . 停了下來，然後有人說: 到了，落轎。\n");
        me->move("/open/world1/tmr/area/street4");
}


