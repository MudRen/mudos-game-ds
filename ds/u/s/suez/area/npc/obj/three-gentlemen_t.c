
inherit ITEM;
inherit F_UNIQUE;
void create()
{
set_name("�T�g�l�h",({"three-gentlemen tree","tree"}));
set_weight(9999);
set("unit","��");
set("long",
      "     �o�T�ʬh��H�e�@��G���Φ��ƦC�A�ѩ󥦭̪�\n"
      " �K���ëD�����q�h��뫫�V���ءA�ӬO���V�s�|�C��\n"
      " �_�ӴN���T�ӤH�b��g�L�����H��§�@��A�ҥH����\n"         
      " ���~���٤����T�g�l�A�]���H�s���ﻫ��C\n"
);   
		set("no_get",1);
		set("no_sac",1);

setup();
}

void init()
{
       add_action("do_search","search");   
}
int do_search(string arg)
{
  object me=this_player();
                    if (arg != "�T�g�l�h" && arg !="tree"&&arg !="three-gentlemen tree" )
                return 0;
                   else
                   {
                              tell_object(me,"�J�Ӥ@�ݡA�o�T��h����G�O���H��N�شӦ��o�˪��I�I�I\n");
                              tell_object(me,"�ݳo�ӧΦ��A���G���ӫ��V�F�䪺�b�Y......\n");
                              tell_object(me,"�i�O�F��u���@�����ܤH�Ӫ�����M���B���s���A���D......\n");
                         }
               return 1;
}
