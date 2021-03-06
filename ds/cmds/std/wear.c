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
        return notify_fail("你的上一個動作還沒完成。\n");
    
    if( !arg )
    {
        race_weapon_prop="weapon_prop";
        race_armor_prop="armor_prop";
        
        str=sprintf(
                "\n  以下是你目前身上的裝備:\n"+
                "\n  武器: %s%s"+
                "%s%s"+
                "%s%s"+
                "\n\n  頭部: %s%s"
                "\n  臉部: %s%s"
                "\n  頸部: %s%s"
                "\n  上身: %s%s"
                "\n  護甲: %s%s"
                "\n  肩膀: %s%s"
                "\n  手腕: %s%s"
                "\n  手掌: %s%s"
                "\n  手指: %s%s"
                "\n  腰部: %s%s"
                "\n  下身: %s%s"
                "\n  腿部: %s%s"
                "\n  足踝: %s%s"
                "\n  足部: %s%s\n%s\n",
                objectp(eq=me->query_temp("weapon"))? eq->short() : "無",
                (objectp(eq) && wizardp(me)) ? "  攻擊力:"+eq->query(race_weapon_prop+"/damage"):"",
                objectp(eq=me->query_temp("secondary_weapon"))? "\n副武器: "+eq->short(): "  ",
                (objectp(eq) && wizardp(me)) ? "  攻擊力:"+eq->query(race_weapon_prop+"/damage"):"",
                objectp(eq=me->query_temp("armor/shield"))? "\n  盾牌: "+eq->short(): "  ",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/head"))? eq->short(): "無",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/mask"))? eq->short(): "無",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/neck"))? eq->short(): "無",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/cloth"))? eq->short(): "無",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/armor"))? eq->short(): "無",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/surcoat"))? eq->short(): "無",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/wrists"))? eq->short(): "無",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/hands"))? eq->short(): "無",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/finger"))? eq->short(): "無",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/waist"))? eq->short(): "無",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/pants"))? eq->short(): "無",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/legging"))? eq->short(): "無",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/ankle"))? eq->short(): "無",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                objectp(eq=me->query_temp("armor/boots"))? eq->short(): "無",
                (objectp(eq) && wizardp(me)) ? "  防禦力:"+eq->query(race_armor_prop+"/armor"):"",
                wizardp(me)? "\n  防禦力合計: "+me->query_temp("apply/armor") : "",
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
        else write("你身上可以裝備的都已經裝上了。\n");
        return 1;
    }

    if( !objectp(ob = present(arg, me)) )
        return notify_fail("你身上沒有這樣東西。\n");

    if( ob->query("equipped") )
        return notify_fail("你已經裝備著"+ob->name()+"了。\n");

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

        if(!j) return notify_fail("此裝備並不適合你這種職業來穿。\n");
    }

    if( ob->query("female_only")
            &&      (string)me->query("gender") != "女性" )
        return notify_fail(ob->name()+"是女性專用的裝備。\n");
    if( ob->query("male_only")
            &&      (string)me->query("gender") != "男性" )
        return notify_fail(ob->name()+"是男性的專用裝備。\n");
    if( ob->query("limit_lv") > me->query("level") )
        return notify_fail("你的等級太低，無法裝備這麼高級的防具。\n");
    if( ob->query("limit_con") > me->query_con() )
        return notify_fail("你的體型不夠，無法裝備這麼大型的防具。\n");
    if( ob->query("limit_str") > me->query_str() )
        return notify_fail("你的力量不夠，裝不動這件防具。\n");
    if( ob->query("limit_int") > me->query_int() )
        return notify_fail("你不夠聰明，不懂得怎麼穿戴它。\n");
    if( ob->query("limit_dex") > me->query_dex() )
        return notify_fail("你想要裝備它，可是你動作慢吞吞的，穿不上去。\n");
    if( ob->query("limit_mks") > me->query("MKS") )
        return notify_fail("你的殺氣不夠應付這件東西。\n");
    if( ob->query("max_lv") < me->query("level") && ob->query("max_lv")>1)
        return notify_fail("這是低等級專用的裝備。\n");
    if( !ob->query_durable() ) return notify_fail("這件裝備損壞了，並不能裝備\n");
    
    if( ob->wear() ) {
        if( !stringp(str = ob->query("wear_msg")) ) {
            // new update ----------------------------------
            switch( ob->query("armor_type") )
            {
            case "shield"  : str = YEL "$N舉起一" + ob->query("unit") + "$n。" NOR;
                break;
            case "head"    : str = YEL "$N套上一" + ob->query("unit") + "$n。" NOR;
                break;
            case "mask"    : str = YEL "$N戴上一" + ob->query("unit") + "$n。" NOR;
                break;
            case "neck"    : str = YEL "$N戴上一" + ob->query("unit") + "$n。" NOR;
                break;
            case "cloth"   : str = YEL "$N穿上一" + ob->query("unit") + "$n。" NOR;
                break;
            case "armor"   : str = YEL "$N裝備一" + ob->query("unit") + "$n。" NOR;
                break;
            case "surcoat" : str = YEL "$N披上一" + ob->query("unit") + "$n。" NOR;
                break;
            case "wrists"  : str = YEL "$N戴上一" + ob->query("unit") + "$n。" NOR;
                break;
            case "hands"   : str = YEL "$N套上一" + ob->query("unit") + "$n。" NOR;
                break;
            case "finger"  : str = YEL "$N穿上一" + ob->query("unit") + "$n。" NOR;
                break;
            case "waist"   : str = YEL "$N繫上一" + ob->query("unit") + "$n。" NOR;
                break;
            case "pants"   : str = YEL "$N穿上一" + ob->query("unit") + "$n。" NOR;
                break;
            case "legging" : str = YEL "$N穿上一" + ob->query("unit") + "$n。" NOR;
                break;
            case "ankle" : str = YEL "$N戴上一" + ob->query("unit") + "$n。" NOR;
                break;
            case "boots"   : str = YEL "$N穿上一" + ob->query("unit") + "$n。" NOR;
                break;
            default        : str = YEL "$N裝備$n。" NOR;
            }
        }
        // ------------------------------------------------

        str += "\n";
        if(me->query_temp("hide")+me->query_temp("invis")<1)
                message_vision(str, me, ob);
        else
        {
            if(me->query("gender")=="女性") gender="妳";
            else gender="你";
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
指令格式﹕wear [<裝備名稱]

A. 這個指令讓你裝備防具。
B. 如果不加任何參數，則可以顯示你所穿的所有裝備。
   (本指令的簡寫指令為「eq」。)

HELP
         );
    return 1;
}


