inherit ROOM;
void create()
{
        set("short", "�����p�����b����");
     set("light",1);
        set("long", @LONG
�A�D�`���L�q���i�J�F�߮�j��-�����p�������b���̡A
�����p�����O�@��C�N�W�j������A�p�G�S����ƧA��
�ӳt�t���}�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"map_18",
 ]));
set("objects",([
       __DIR__"npc/left" : 1,
    ]) );
   set("no_clean_up", 0);
 setup();
        replace_program(ROOM);
}

 
