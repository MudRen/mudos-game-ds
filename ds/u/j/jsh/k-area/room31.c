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
        set("short", "���x�����з|ĳ��");
        set("long", @LONG
�o�̬O���x�F���}�|�Ϊ��|ĳ�ǡA��ꪺ������\�ۤC�i�Ȥl�A�e
    �豾�۶ªO�٦��X�T���ϡA�z�L����ݹL�h�i�H�ݨ춰�X���C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"west" : __DIR__"room12",
  "south" : __DIR__"room34",
  //"north" : __DIR__"room26",
  //"east" : __DIR__"room28",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

