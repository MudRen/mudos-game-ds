inherit ROOM;
void create()
{
        set("short", "�_��");
     set("light",1);
        set("long", @LONG
�o�̬O�߮���H�窺�ж�A�Q������A�A�ݨ짧�B�̥��b�V�O�ѥСA
�����٦��X�Ӥp�Ĥl�A���G�ܫܷQ�ܱj�A�@�����ۤ�M���V�_��H�A
�Q��������C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"map_5",
  ]));
 set("objects",([
       __DIR__"npc/japen_child" : 2,
       __DIR__"npc/scare" : 3,
    ]) );

   set("outdoors","land");
 set("no_clean_up", 0);
 setup();
        }
