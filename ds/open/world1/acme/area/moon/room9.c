inherit ROOM;

void create()
{
        set("short","�P��չ�");
        set("long", @LONG
�o�̪����¶�ۤ@�h���������A�n���Y�����L�A�y�ɧAı�o�ۤv
�ϩ��m�����ƴ���L���۹Ҥ����C�A�u���������ݨ����񦳵۬y���B
�B�p���B�p�s�C�B�ն��C�A���զ��]ť�o��ǳ\���ͻﳾ�s�A�o�̸�
���Z�����ФH�����۷��ת����P�C��A�ݨ체�e���o�T���H�A�A�w�|
ı�o�߯��ŵM�}�ԡC�o�̪��]�߫D�`�����@�ˡA���G���ɡA�Ѫ�
�N�|�b�a�W�����ۻȦǦ⪺�G���A�o�O�]������z�L�����A���o�X�@
�B�I�����u�A�u�n�O�ݹL�o�ˬ������H�A���w�|�j�Y�@��A�]�|�O�L
�̥å����ѡI
LONG
        );
        set("exits",([
  "down" : __DIR__"room8.c",
]));
        set("light",1);
        set("objects",([
__DIR__"item/elder_box" :1,
]));

        set("no_kill",1);
        setup();
        set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
        call_other( "/obj/board/moon_room9_b", "???" );
}

