inherit ROOM;

void create()
{
        set("short", "�ө���йD�㩱");
        set("long", @LONG
�o�̬O�䳣�ө��󤤪��Z�����A�����f���۱Ƶe�ۤӶ����G�A��ܱq�դ�
    ��ߤW������~�A�������[�l�B�d�l�W�̺�������a�Ʃ�ۦU���D��C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room40",
  "southwest" : __DIR__"room44",
  //"north" : __DIR__"room34",
  "east" : __DIR__"room45",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

