
inherit ROOM;

void create()
{
 set("short","�����O");
        set("long",@LONG
�o�������O�]�����D��������̡A�䤤�s�Ӥp�𳣨S���A���i�h���H
�Q���g�������A���L�J�Ӥ@�ݡA�ï󤧤����G���ɫؿv���A�S�n�����O�C
����A�Q�ਭ���}�ɡA��Mı�o�n��������a�褣��A�o������A���G��
�Ӧ۵M�A���D�u�����H......�H
LONG
        );

         set("exits", ([
         "west": __DIR__"path_t",
         "southeast": __DIR__"seven_d1",
         "northeast": __DIR__"seven_l1",
         ]));
        
        set("outdoors","land");
        
        setup();


 }
void init()
{
        add_action("do_search", "search");
}
void do_search(object me,string arg)
{

        if (arg != "���O"  )
                return 0;
      else{
        message_vision( "$N�J�ӧ�F����񪺯��O�A���M�o�{�@�����M�`���j�ۡI\n\n"  ,me);
         set("item_desc",([
        "�j��":"�o�̪��j�ۤW�����ݨ��X��r�u�_�椧�`�A�̦ͪV��A���̦V�F�C�v \n
                                 ��     ��                                   \n
                                                                             \n
                ��         ��                     ��                         \n
                                                                             \n
                                                                             \n
                   ��      ��                                                \n
                                                                             \n
                 �z����....�o�⤰��_��C�P��.....-.-\n"       
         ]));
}
}