inherit ROOM;
void del_temp();
void create()
{
        set("short", "�T�s��");
        set("long", @LONG
�ݨ��礤�h�L���A�������ҩM��W�{�۴H�����M�C�A�A����
�ߤ��t�ġG�p���K�x�A���ǯ��a��L�ġC�A�Q��[�g�w�h���Ѵ�
�x�A�A���ѷn�F�n�Y�C
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
        tell_object(me,"�e������ĤѡA�ݨӤQ�����M�I�E\n");
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
