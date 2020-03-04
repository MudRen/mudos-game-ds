inherit ROOM;
void del_temp();
void create()
{
        set("short", "固山寨");
        set("long", @LONG
看到營中士兵那鮮明的盔甲和手上閃著寒光的刀劍，你不由
心中暗嘆：如此鐵軍，難怪能縱橫無敵。再想到久經安逸的天朝
軍，你不由搖了搖頭。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"camp018",
  "south" : __DIR__"camp020",
  "west" : __DIR__"camp016",
]));
 set("objects", ([
       __DIR__"mob/camp_guard" : 1+random(2),
                ]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
       me=this_player();
    
       ::valid_leave(); 
       if ( this_object()->query_temp("cannot_north") &&  ( (dir=="north") )){ 
        tell_object(me,"前方火光衝天，看來十分的危險•\n");
       }
       else return ::valid_leave(me,dir);

} 
void del_temp()
{
     this_object()->add_temp("del",1);
     call_out("del_temp",60);
     if( !this_object()->query_temp("del") ) return;
     this_object()->delete_temp("cannot_north"); 
     this_object()->delete_temp("del");
     return;
}
