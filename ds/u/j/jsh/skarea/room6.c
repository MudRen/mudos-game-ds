inherit ROOM;

void create()
{
        set("short", "�䳣�j�D");
        set("long", @LONG
�o�̬O�e�q�䳣���D�n�D���A�����۷�e��ӥB����A��ǪL�ߵ۰Ӯa�B��
���A���䪺�ø��i�H�q��������C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room9", 
  "west" : __DIR__"room3", 
  "south": __DIR__"room13",
  "north": __DIR__"room5",]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


