// Room: /u/l/luky/room/pearl_40.c
inherit ROOM;
void create()
{
set("short", "[1;32m�|����[m");
set("long", @LONG
�V�L�j�U�~�򩹤W����F�|���ǡA�S�V�n���N���F�i�Ӧ��G����
§���A���L����|�����O�M�����e��ܦo�ä��b�N�A�[�ݩP����
�ҡA�\�۱i�Ѯ�(Table)�A�@�u���d(Case)�A����ꪺ�u�@�СC

LONG
);
set("objects",([
__DIR__"npc/perfect":1,
]));
set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"pearl_37",
]));
set("item_desc",([
"table":"�u�\\�F�X�i��(Paper)�A�M�@���|�����b�ݪ���(book)�A��M���ͨ�
�|���ݮѤF..\n",
"case":"���p�o�Ӧa��Ӧ����A���O�������Ǫ��ѡA�S�O���C\n",
"book":"���Q�ӬݮѤ��b�g����ɡA�|�����N�ѻפF�_��..�O�������f�ܡH
�|���y�W�����e�S�ݤ��X��ԣ�߾�..�O�h�ߦn�F..\n",
"paper":"�ȤW�K�K�³ª��g�����p�L�C�몺��r(Word)�A�u���Ū���֬ݤ���
�A�ݨӬO�|����ݮ��䰵���O..�Ӿ߰Q�ۤv�F..\n",
"word":"�򥻬ݤ�����!!�ݰݰ|���a..\n",
]));
set("no_magic",1);
set("no_kill",1);
set("no_cast",1);
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
