#include <ansi.h>

inherit ROOM;

void create()
{
set("short","�s�f");
 set("long", @LONG
�o�̬O�R�����q������C���p�������f�A�b�����ӥi�Hť��@�q�@�q��
�����n�C�A�ݨ���䦳�@�ʤj��A��F�W�v�F�i�֭��A�W���g�F�@�Ǭ��r�C
���G�O�@��ĵ�i���Х�(sign)�C
LONG
);
set("item_desc",([
"sign":HIR"\nĵ�i�G���B�s�Ϧ����إͪ��X�S�A�����ήȫȪ`�N�A�T�H�H�U����ФŤJ�s�I\n\n"NOR,
]));

set("exits",([
  "southeast":__DIR__"al10",
  "westup":__DIR__"m2",]));
 set("objects",([
 ]));
setup();
}
