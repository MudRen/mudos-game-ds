inherit ROOM;

void create()
{
      set ("short", "�����p�|");
      set ("long", @LONG
�o�̥|�g���۳\�h�Q�ճ��л\���Ӫ��A�۹�ūפ]�V�ӶV�H�N�A�ϧA�}�B
�Q�[�֡A�ɧ����}�o�̡A��@�ӷŷx���a��Ӧn�n�𮧤@�f�A�p�|�@���V�W��
���ӥh�C
LONG);
      
  set("exits", ([ 
  "north" : __DIR__"snow6",
  "southeast" : __DIR__"snow4", 
  ]));

  set("outdoors", "snow"); 
  set("no_clean_up", 0);

  setup();
}
