/*
  Name: /cmds/std/wield.c
  Copyright: DS
  Author/Modify: Alickyuen
  Date: 04/08/05 01:24
  Description: 
*/

inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
        object ob, *inv;
//		object old_wp;
//		string str,gender;
        int i, count;
        if(me->is_busy() || me->is_block())
                return notify_fail("�A���W�@�Ӱʧ@�٨S�����C\n");
        if( !arg ) return notify_fail("�A�n�˳Ƥ���Z���S\n");

        if(arg=="all") {
                inv = all_inventory(me);
                for(count=0, i=0; i<sizeof(inv); i++) {
                        if( inv[i]->query("equipped") ) continue;
                        if(do_wield(me, inv[i]) ) count ++;
                }
                write("Wield all OK!!\n");
                return 1;
        }

        if( !objectp(ob = present(arg, me)) )
                return notify_fail("�A���W�S���o�˪F��C\n");

        if( ob->query("equipped") )
                return notify_fail("�A�w�g�˳Ƶ�"+ob->name()+"�F�C\n");
        
//		����: �۰ʨ���������Z��
//		�������/feature/equip.c �b�o�̳]�w�|����˰Ƥ�Z��
//		-Alickyuen@DS 2005 Aug 3
// 
//        if( old_wp = me->query_temp("weapon") )
//        {
//            if(old_wp->unequip() )
//            {
//                if( !stringp(str = old_wp->query("unwield_msg")) )
//                        str = "$N��U�⤤��$n�C\n";
//                if(me->query_temp("hide")+me->query_temp("invis")<1) message_vision(str, me, old_wp);
//                else
//                {       
//                        if(me->query("gender")=="�k��") gender="�p";
//                        else gender="�A";
//                        str=replace_string( str, "$N", gender);
//                        str=replace_string( str, "$n", old_wp->name());
//                        tell_object(me,str);
//                }
//            }
//        }
        return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
        string str, gender;
        mapping class_c;
        int i, j=0;

        if( (arrayp(class_c = ob->query("class_only")) || stringp(class_c = ob->query("class_only"))) && me->query("class1") != "adventurer" )
        {
          if(arrayp(class_c))
            for(i=0; i<sizeof(class_c); i++)
            {
              if(me->query("class1") != class_c[i]) continue;
              j++;
            }

          if(stringp(class_c))
            if(me->query("class1") == class_c) j++;

          if(!j) return notify_fail("�A�յ۸˳�"+ob->name()+"�A�����Z���P�A�ҾǤ��X�ӵL�k�˳ơC\n");
        }


        if( ob->query("female_only")
        &&      (string)me->query("gender") != "�k��" )
                return notify_fail(ob->name()+"�O�k�H�M�Ϊ��Z���C\n");
        if( ob->query("male_only")
        &&      (string)me->query("gender") != "�k��" )
                return notify_fail(ob->name()+"�O�k�H�M�Ϊ��Z���C\n");
        if( ob->query("limit_lv") > me->query("level") )
                return notify_fail("�A�����ŤӧC�A�L�k�˳�"+ob->name()+"�C\n");
        if( ob->query("limit_con") > me->query_con() )
                return notify_fail("�A���髬�����A�L�k�˳�"+ob->name()+"�C\n");
        if( ob->query("limit_str") > me->query_str() )
                return notify_fail("�A���O�q�����A������"+ob->name()+"�C\n");
        if( ob->query("limit_int") > me->query_int() )
                return notify_fail("�A�����o���A�����o���ϥ�"+ob->name()+"�C\n");
        if( ob->query("limit_dex") > me->query_dex() )
                return notify_fail("�A�յ۸˳�"+ob->name()+"�A�i�O�A�����ӺC�F���p�ߥ���ۤv�C\n");
	if( ob->query("limit_mks") > me->query("MKS") ) 
		return notify_fail("�A�����𤣰����I�o��F��C\n");
        if( ob->query("limit_skill") > me->query_skill((string)ob->query("skill_type"),1) )
                return notify_fail("�A���ըϥ�"+ob->name()+"�A�i�O�A���ޥ������C\n");
                
        if( ob->wield() )
        {
                if( !stringp(str = ob->query("wield_msg")) )
                        str = "$N�˳�$n�@�Z���C\n";
                if(me->query_temp("hide")+me->query_temp("invis")<1) message_vision(str, me, ob);
                else
                {       
                        if(me->query("gender")=="�k��") gender="�p";
                        else gender="�A";
                        str=replace_string( str, "$N", gender);
                        str=replace_string( str, "$n", ob->name());
                        tell_object(me,str);
                }
        if(me->is_fighting()) me->add_block(1);
                return 1;
        } else
                return 0;
}

int help(object me)
{
        write(@HELP
���O�榡�Rwield <�˳ƦW��>
 
�o�ӫ��O���A�˳ƬY�󪫫~�@�Z��, �A���ݭn�֦��o�˪��~.
 
HELP
    );
    return 1;
}

