inherit ROOM;

void create()
{
        set("short", "�e���k�Ϥ���");
        set("long", @LONG
�o�̬O�e�������k�Ϸ����E���ж��A�e�������C�@�Ӫ��ѳ��|���U
�۪��ж��A�����E�]���ҥ~�A�b�o�����f�ǡA���@��ꪺ�a�L�A���j
�ӮɡA�N�|���m�m�����T�G�M�ܪ��n���A�b�o�̦��X�i��l�A�W������
�\�h�M�C��L������A��O�o�̴����\�h�����A�����E�b����W���W�n
�������W�A��ƹL�j�������W�U�C
LONG
        );
        set("valid_startroom", 1);
        set("light",1);
        set("objects",([
  "/obj/money/coin":400,
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

