inherit ROOM;
void create()
{
          set("short","��v�ϤJ�f");
          set("long",@LONG
�o�̴N�O���q�ϮǪ���v�ϡA��b�o���h�O�q�u�M�L�̪��a�H�C����
���q�u�b�o�~�N�Q�C�����c�ʦ�~�A�ҥH�o�̧����C�K�צ�v�C�o�̨ө�
�q�u�D�`��K�A���q�u�C�Ѫ��u�@�ɶ����[�C
LONG
          );
          set("world", "future");
        set("outdoors","desert");
          set("exits", ([ /* sizeof() == 2 */
	  "south" : __DIR__"digging_street4",
          ]));
          set("item_desc",([
               "�ۨ�":
"�@���������ۨ�A�W����ۡG�u�o�̥u�}�񵹤w�n�O�~���C�v\n",
]) );
          set("no_clean_up", 0);
          setup();
          replace_program(ROOM);
}
