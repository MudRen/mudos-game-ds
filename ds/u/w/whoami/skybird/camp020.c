#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�T�s��");
        set("long", @LONG
�ݨ��礤�h�L���A�������ҩM��W�{�۴H�����M�C�A�A����
�ߤ��t�ġG�p���K�x�A���ǯ��a��L�ġC�A�Q��[�g�w�h���Ѵ�
�x�A�A���ѷn�F�n�Y�C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"camp019",
  "south" : __DIR__"camp021",
  "east" : __DIR__"camp024",
]));
 set("objects", ([
       __DIR__"mob/general_guard" : 2+random(3),
                ]));

        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
   me = this_player();
    if (present("general guard",environment(me)) &&  ( (dir=="east") ))
       {
        message_vision(YEL"�N�x�@�û��R���Ӥj�b�Z�O$N��i�h���I\n"NOR,me);
       } 
    else return ::valid_leave(me,dir);

}

