inherit ROOM;

void create()
{
        set("short", "�䳣�j�D");
        set("long", @LONG
�o�̬O�e�q�䳣���D�n�D���A�����۷�e��ӥB����A��ǪL�ߵ۰Ӯa�B��
���A���䪺�ø��i�H�q��������C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"room14", 
  "west" : __DIR__"room10", 
  "north":__DIR__"room6",
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}

