/*
  [�t�m]���G�c(Fruiterer)
  [�t�m]�׳c(Meatman)
  [�t�m]���c(Fishmonger)
  [�t�m]��c(Greengroser)
*/
//���x���x 1 ��
inherit ROOM;

void create()
{
        set("short", "�䳣�j�D");
        set("long", @LONG
�o�̬O�e�q�䳣���D�n�D���A�����۷�e��ӥB����A��ǪL�ߵ۰Ӯa�B��
    ���A���ǥi�H�ݨ���x�������j���Ϋؿv�C 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room13",
  "south" : __DIR__"room35",
  "north" : __DIR__"room29",
  "east" : __DIR__"room33",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

