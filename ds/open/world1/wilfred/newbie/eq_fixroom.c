inherit ROOM;
void create()
{
  set("short", "�u�@�i��");
  set("long", @LONG

�o�̬O���l�Ǫ��@���Ŧa�A�o�̩�ۤ@���ݨӬ۷�I��
���j�K�z�A�W�Y�\�ۼƶ������Ϊ��K���A�b�@�Ǫ��a�W����
�ۤ@�a�����K�u��A�p�G���ݭn�A�z�i�H�N�a�����Z���θ�
�ƥ浹���K�Ѯv�խײz [0;1;36m([1mg[1mi[1mv[1me[1m [1mm[1ma[1ms[1mt[1me[1mr[1m [1m<[1m�[1m�[1m�[1m~[1m [1mi[1md[1m>[1m)[0m
LONG
);
  set("exits", ([
  "west" : "/open/world1/tmr/area/smithy",
]));
  set("no_clean_up", 0);

  set("objects",([
__DIR__"eq_master" : 1,
]) );
  set("light",1);
  setup();
  replace_program(ROOM);
}

