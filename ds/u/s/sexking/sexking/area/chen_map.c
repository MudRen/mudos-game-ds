inherit ROOM;
void create()
{
        set("short", "�p���`���b��");
     set("light",1);
        set("long", @LONG
�o�̬O�饻�ӤH�p���`���Ҧ��b���A�P���\�F�����f�A�A�i�H
�V�p���`���K�ʡC
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"map_6",
 ]));
set("objects",([
       __DIR__"npc/chen" : 1,
    ]) );
 
   set("no_clean_up", 0);
 setup();
        replace_program(ROOM);
}
