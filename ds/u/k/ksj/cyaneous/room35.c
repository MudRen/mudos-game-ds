inherit ROOM;

void create()
{
        set("short", "�䳣�j�D");
        set("long", @LONG
�o�̬O�e�q�䳣���D�n�D���A�����۷�e��ӥB����A��ǪL�ߵ۰Ӯa�B��
    ���A�q���䪺�D���ݹL�h�i�H�ݨ�ꬣ�������C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room14",
  "south" : __DIR__"room39",
  "north" : __DIR__"room32",
  //"east" : __DIR__"room34",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

