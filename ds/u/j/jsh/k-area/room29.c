/*
  [�t�m]���G�c(Fruiterer)
  [�t�m]�׳c(Meatman)
  [�t�m]���c(Fishmonger)
  [�t�m]��c(Greengroser)
*/
inherit ROOM;

void create()
{
        set("short", "'�䳣�j�D");
        set("long", @LONG
�o�̬O�e�q�䳣���D�n�D���A�����۷��e��ӥB����A��ǪL�ߵ۰Ӯa�B��
    ���A���䪺�ø��i�H�q��������C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room12",
  "south" : __DIR__"room32",
  "north" : __DIR__"room26",
  //"east" : __DIR__"room28",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}
