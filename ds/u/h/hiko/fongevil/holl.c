inherit ROOM;
void create()
{
        set("short", "�s�}");
        set("long",@LONG
�A�Ө�F�s�}���A�s�}���º������A���M�n���@�F�����ۧA�A��
�M�Ať��@�n�~�q�A��ӬO�@���j�º��b�A���e�A���������Q������
�A�ݨӧA�O�I�J�F�e���a�L�F�C
LONG
        );
  
set("exits", ([
  "north" : __DIR__"holl-n",  "out" : __DIR__"mu18",
   ]) );       
set("objects",([
  __DIR__"npc/black_bear" : 1,
        ]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
 }
 

 int valid_leave(object me, string dir)
{
  object guard;
  if( objectp(guard=present("black bear", this_object())) && dir == "north" )
  {
    message_vision("�@�n��q�A$n���M���F�L�ӡA�u���e�צb$N���e�A����$N�L�h�C\n",me ,guard);
        return notify_fail("");
  }
  return ::valid_leave(me, dir);
}




