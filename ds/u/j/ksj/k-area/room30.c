/*
  [�t�m]���G�c(Fruiterer)
  [�t�m]�׳c(Meatman)
  [�t�m]���c(Fishmonger)
  [�t�m]��c(Greengroser)
*/
//���x 4 ��
inherit ROOM;

void create()
{
        set("short", "���x�����ж��X��");
        set("long", @LONG
�o�̬O���x�����X���A���x���㶤�B�޽m�M�˾\���b�o��i��A���W���Ǯ�
    �x���b�i��V�m�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"west" : __DIR__"room12",
  "south" : __DIR__"room33",
  //"north" : __DIR__"room26",
  //"east" : __DIR__"room28",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

