        
inherit ROOM;

void create()
{
        set("short", "�}�����Y");
        set("long", @LONG
�o�̤w�g�O�s�}�̪����Y�A��Ǫ������w�g�鸨���֡A�a�W�����֪G
�ꪺ���e�A���G���ʪ��~��b�o�̡C

LONG
);
        set("exits",([
        "south" : __DIR__"map_4_15",
        ]));
        set("outdoors","forest");
        set("objects",([
                 __DIR__"npc/bigfoxbear":1,
                  "/obj/stake":4,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

