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
        set("short", "���x�����п줽��");
        set("long", @LONG
�o�̬O���x�줽�ǡA�����\�F�@�i�j�j���줽��A����ߵۤ@�ǺX
    �l�A�k�䪺��W�h�i�K�۳\�h���a���A������W�X�Ӥj�r�g��
    "���x�䳣����"�A�n��]���@�Ӥp�c�СC 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room33",
  "south" : __DIR__"room37",
  "north" : __DIR__"room31",
  //"east" : __DIR__"room34",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

