
inherit ROOM;

void create()
{
 set("short","���O");
        set("long",
"���H�����M��V�������O�C\n"
        );

         set("exits", ([
         "east": __DIR__"grass",
         "west":__DIR__"grass",
         "north":__DIR__"grass",
         "south": __DIR__"grass",
         "northwest": __DIR__"grass",
         "northeast": __DIR__"seven_l2",
         "southwest": __DIR__"grass",
         "southeast": __DIR__"grass",
         ]));
         set("item_desc",([
       "�۴���":"�W���g�ۡG�u�̤ͪ��͡A���̤����C�v\n"
         ]));
        
        set("outdoors","land");
        
        setup();

        replace_program(ROOM);

 }
