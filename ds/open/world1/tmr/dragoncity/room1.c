inherit ROOM;
void create()
{
  set ("short", "�u�a");
  set ("long", @LONG

�o�̦��@�ǵL�ҬO�ƪ��u�H�A�άO����A�άO�ܰs
�A�άO��ѡA�@���p�l�����������F�贲���@�a�A
�ݨӳo���٭n���@�ǮɭԤ~��ئn�C

�A�ݨ�@�Ӥ@�y��˪��H���b�@�Ǫ��𮧰ϡA��W
�ٮ��ۤ@�i�ŹϡA���ɪ��C�Y�I���

LONG
);

  set("exits", ([
"out" : "/open/world1/wilfred/sand/room45",
]));

  set("item_desc", ([
"�@�y��˪��H" : "�@�Ө���¦�Ũ�m�A�`�Ŧ���J�Ǫ��H�A������Źϵo�b�C\n�L���Z�\\�v�g��F�@���Q�����ҬɡC\n",
"�Ź�" : "�W���K�K�³ª����O�u���A���G�O�������a�ϡA�k�䪺�ťճB�g�F�Ƥd�檺�{���X�C\n" ,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

