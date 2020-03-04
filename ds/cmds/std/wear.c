/*
  Name: /cmds/std/wear.c
  Copyright: DS2
  Author: Alickyuen
  Date: 04/08/05 02:00
  
  last update by tmr 2006/11/27
*/


#include <ansi.h>

inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
    object ob, *inv,eq;
      int i, count;
    string str,race_weapon_prop,race_armor_prop;
    if(me->is_busy() || me->is_block())
        return notify_fail("�A���W�@�Ӱʧ@�٨S�����C\n");
    
    if( !arg )
    {
        race_weapon_prop="weapon_prop";
        race_armor_prop="armor_prop";
        
        str=sprintf(
                "\n  �H�U�O�A�ثe���W���˳�:\n"+
                "\n  �Z��: %s%s"+
                "%s%s"+
                "%s%s"+
                "\n\n  �Y��: %s%s"
                "\n  �y��: %s%s"
                "\n  �V��: %s%s"
                "\n  �W��: %s%s"
                "\n  �@��: %s%s"
                "\n  �ӻH: %s%s"
                "\n  ���: %s%s"
                "\n  ��x: %s%s"
                "\n  ���: %s%s"
                "\n  �y��: %s%s"
                "\n  �U��: %s%s"
                "\n  �L��: %s%s"
                "\n  ����: %s%s"
                "\n  ����: %s%s\n%s\n",
                objectp(eq=me->query_temp("weapon"))? eq->short() : "�L",
                (objectp(eq) && wizardp(me)) ? "  �����O:"+eq->query(race_weapon_prop+"/damage"):"",
                objectp(eq=me->query_temp("secondary_weapon"))? "\n�ƪZ��: "+eq->short(): "  ",
                (objectp(eq) && wizardp(me)) ? "  �����O:"+eq->query(race_weapon_prop+"/damage"):"",
                objectp(eq=me->query_temp("armor/shield"))? "\n  �޵P: "+eq->short(): "  ",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/head"))? eq->short(): "�L",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/mask"))? eq->short(): "�L",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/neck"))? eq->short(): "�L",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/cloth"))? eq->short(): "�L",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/armor"))? eq->short(): "�L",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/surcoat"))? eq->short(): "�L",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/wrists"))? eq->short(): "�L",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/hands"))? eq->short(): "�L",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/finger"))? eq->short(): "�L",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/waist"))? eq->short(): "�L",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/pants"))? eq->short(): "�L",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/legging"))? eq->short(): "�L",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/ankle"))? eq->short(): "�L",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/boots"))? eq->short(): "�L",
                (objectp(eq) && wizardp(me)) ? "  ���m�O:"+eq->query(race_armor_prop+"/armor"):"",
                wizardp(me)? "\n  ���m�O�X�p: "+me->query_temp("apply/armor") : "",
            );

        write(str);
        return 1;
    }

    if(arg=="all") {
        inv = all_inventory(me);
        for(count=0, i=0; i<sizeof(inv); i++) {
            if(!inv[i]) continue;
            if( inv[i]->query("equipped") ) continue;
            if(do_wear(me, inv[i]) ) count ++;
        }
        if(count>0) write("Ok.\n");
        else write("�A���W�i�H�˳ƪ����w�g�ˤW�F�C\n");
        return 1;
    }

    if( !objectp(ob = present(arg, me)) )
        return notify_fail("�A���W�S���o�˪F��C\n");

    if( ob->query("equipped") )
        return notify_fail("�A�w�g�˳Ƶ�"+ob->name()+"�F�C\n");

    return do_wear(me, ob);
}

int do_wear(object me, object ob)
{
    string str,gender;
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

        if(!j) return notify_fail("���˳ƨä��A�X�A�o��¾�~�Ӭ�C\n");
    }

    if( ob->query("female_only")
            &&      (string)me->query("gender") != "�k��" )
        return notify_fail(ob->name()+"�O�k�ʱM�Ϊ��˳ơC\n");
    if( ob->query("male_only")
            &&      (string)me->query("gender") != "�k��" )
        return notify_fail(ob->name()+"�O�k�ʪ��M�θ˳ơC\n");
    if( ob->query("limit_lv") > me->query("level") )
        return notify_fail("�A�����ŤӧC�A�L�k�˳Ƴo�򰪯Ū�����C\n");
    if( ob->query("limit_con") > me->query_con() )
        return notify_fail("�A���髬�����A�L�k�˳Ƴo��j��������C\n");
    if( ob->query("limit_str") > me->query_str() )
        return notify_fail("�A���O�q�����A�ˤ��ʳo�󨾨�C\n");
    if( ob->query("limit_int") > me->query_int() )
        return notify_fail("�A�����o���A�����o���������C\n");
    if( ob->query("limit_dex") > me->query_dex() )
        return notify_fail("�A�Q�n�˳ƥ��A�i�O�A�ʧ@�C�]�]���A�藍�W�h�C\n");
    if( ob->query("limit_mks") > me->query("MKS") )
        return notify_fail("�A�����𤣰����I�o��F��C\n");
    if( ob->query("max_lv") < me->query("level") && ob->query("max_lv")>1)
        return notify_fail("�o�O�C���űM�Ϊ��˳ơC\n");
    if( !ob->query_durable() ) return notify_fail("�o��˳Ʒl�a�F�A�ä���˳�\n");
    
    if( ob->wear() ) {
        if( !stringp(str = ob->query("wear_msg")) ) {
            // new update ----------------------------------
            switch( ob->query("armor_type") )
            {
            case "shield"  : str = YEL "$N�|�_�@" + ob->query("unit") + "$n�C" NOR;
                break;
            case "head"    : str = YEL "$N�M�W�@" + ob->query("unit") + "$n�C" NOR;
                break;
            case "mask"    : str = YEL "$N���W�@" + ob->query("unit") + "$n�C" NOR;
                break;
            case "neck"    : str = YEL "$N���W�@" + ob->query("unit") + "$n�C" NOR;
                break;
            case "cloth"   : str = YEL "$N��W�@" + ob->query("unit") + "$n�C" NOR;
                break;
            case "armor"   : str = YEL "$N�˳Ƥ@" + ob->query("unit") + "$n�C" NOR;
                break;
            case "surcoat" : str = YEL "$N�ܤW�@" + ob->query("unit") + "$n�C" NOR;
                break;
            case "wrists"  : str = YEL "$N���W�@" + ob->query("unit") + "$n�C" NOR;
                break;
            case "hands"   : str = YEL "$N�M�W�@" + ob->query("unit") + "$n�C" NOR;
                break;
            case "finger"  : str = YEL "$N��W�@" + ob->query("unit") + "$n�C" NOR;
                break;
            case "waist"   : str = YEL "$Nô�W�@" + ob->query("unit") + "$n�C" NOR;
                break;
            case "pants"   : str = YEL "$N��W�@" + ob->query("unit") + "$n�C" NOR;
                break;
            case "legging" : str = YEL "$N��W�@" + ob->query("unit") + "$n�C" NOR;
                break;
            case "ankle" : str = YEL "$N���W�@" + ob->query("unit") + "$n�C" NOR;
                break;
            case "boots"   : str = YEL "$N��W�@" + ob->query("unit") + "$n�C" NOR;
                break;
            default        : str = YEL "$N�˳�$n�C" NOR;
            }
        }
        // ------------------------------------------------

        str += "\n";
        if(me->query_temp("hide")+me->query_temp("invis")<1)
                message_vision(str, me, ob);
        else
        {
            if(me->query("gender")=="�k��") gender="�p";
            else gender="�A";
            str = replace_string( str, "$N", gender);
            str = replace_string( str, "$n", ob->name());
            tell_object(me, str);
        }

        if(me->is_fighting()) me->add_block(1);
        return 1;
    }  //  if( ob->wear() )

        return 0;
}

int help(object me)
{
    write(@HELP
���O�榡�Rwear [<�˳ƦW��]

A. �o�ӫ��O���A�˳ƨ���C
B. �p�G���[����ѼơA�h�i�H��ܧA�Ҭ諸�Ҧ��˳ơC
   (�����O��²�g���O���ueq�v�C)

HELP
         );
    return 1;
}


