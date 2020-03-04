// rankd.c
// ��s���: 1999.10.23
// ��s��: Shengsan

#include <ansi.h>

string query_rank(object ob)
{
          string eff_class, id;
        if( ob->query("class2") ) eff_class=ob->query("class2");
        else if( ob->query("class1") ) eff_class=ob->query("class1");
        else if( ob->query("class") ) eff_class=ob->query("class");
        else eff_class="none";

        if( ob->is_ghost() ) return HIB "�i ��  �� �j" NOR;
        id=ob->query("id");
        if(wizardp(ob))
        {
                 switch(wizhood(ob))
                  {
                        case "(admin)":                 return HIW "�i �j  �� �j" NOR;
                        case "(arch)":                  return HIY "�i �j�Ův �j" NOR;
                        case "(wizard)":                return HIG "�i ��  �v �j" NOR;
                        case "(apprentice)":    return HIM "�i ���ߥ� �j" NOR;
                        default:                                return HIM "�i �y  �� �j" NOR;
                  }
        }        
        
        switch(ob->query("gender"))
        {
                case "�k��":
                        if( ((int)ob->query("PKS") > 4999) ) return HIM"�i ��  ù �j"NOR;
                        if( ((int)ob->query("PKS") > 999) ) return HIM"�i �d�H�� �j"NOR;
                        if( ((int)ob->query("PKS") > 99) ) return HIR"�i �ʤH�� �j"NOR;
                        if( ((int)ob->query("PKS") > 30) ) return RED"�i ���H�] �j"NOR;
                        switch(eff_class)
                        {
                            case "�K����":        return "�i �k�Z�� �j";
                            case "�e����":        return "�i �k�C�� �j";
                            case "���Z��":                return "�i �k�D�h �j";
                            case "thief":                return "�i �k  �s �j";
                            case "�ⶳ�x":                return "�i ��  �h �j";
                            case "adventurer":        return "�i �k�i�� �j";
                            case "������":                return "�i �k�@�� �j";
                            case "�H����":        return "�i �k�D�h �j";
                            case "�֫ӭx":        return "�i �x  �H �j";
                            case "�����v":        return "�i �]  �� �j";
                            case "�ѱ���":        return "�i �k�w�v �j";
                            default:                return "�i �p�k�� �j";
                        }         
        
                default:
                        if( ((int)ob->query("PKS") > 4999) ) return HIM"�i ��  �� �j"NOR;
                        if( ((int)ob->query("PKS") > 999) ) return HIM"�i �d�H�� �j"NOR;
                        if( ((int)ob->query("PKS") > 99) ) return HIR"�i �ʤH�� �j"NOR;
                        if( ((int)ob->query("PKS") > 30) ) return RED"�i ���H�] �j"NOR;
                        switch(eff_class)
                        {
                            case "�K����":        return "�i �Z  �� �j";
                            case "�e����":        return "�i �C  �� �j";
                            case "���Z��":        return "�i �D  �h �j";
                            case "thief":         return "�i �p  �� �j";
                            case "adventurer":    return "�i �_�I�� �j";
                            case "�ⶳ�x":        return "�i ��  �Q �j";
                            case "�H����":        return "�i �D  �h �j";
                            case "�֫ӭx":        return "�i �x  �H �j";
                            case "�����v":        return "�i �]  �� �j";
                            case "�ѱ���":        return "�i �w  �v �j";
                            default:              return "�i �s  �� �j";
                        }
        }
}

string query_level(object ob)
{
          string rank;
        rank = ob->query("guild_rank");
        if(!rank) {
                if( ob->query("gender") == "�k��" )
                        rank = "��V���Ъ��p���k";
                else
                        rank = "�|�B���a���y���~";        
        }
        
        return rank;
}


string query_respect(object ob)
{
        int age;
        string str,eff_class;
        if(!ob) return "�B��";
        if( stringp(str = ob->query("rank_info/respect")) )
                return str;
        if(ob->query("race")=="beast") return "�F�~";
        if(ob->query("race")=="monster") return "�F�~";
        if(ob->query("race")=="protoss")
                return "���ڪB��";
        if(ob->query("race")=="zerg")
                return "�����B��";

        if( ob->query("class2") ) eff_class=ob->query("class2");
        else if( ob->query("class1") ) eff_class=ob->query("class1");
        else if( ob->query("class") ) eff_class=ob->query("class");
        else eff_class="none";
        
        age = ob->query("age");
        switch(ob->query("gender"))
        {
                case "�k��":
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                                if( age < 18 ) return "�p�f�f";
                                                else if( age < 30 ) return "�h�Q";
                                                else if( age < 50 ) return "�p�j";
                                                else if( age < 70 ) return "�Ӥ�";
                                                else if( age < 100 ) return "�C�C";
                                                else return "�ѫe��";
                                                break;
                        }

                default:
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                                if( age < 20 ) return "�p�̧�";
                                                else if( age < 30 ) return "�S�x";
                                                else if( age < 60 ) return "����";
                                                else if( age < 80 ) return "����";
                                                else if( age < 100 ) return "�Ѥ���";
                                                else return "�ѫe��";
                                                break;
                        }
        }
}

string query_rude(object ob)
{
        int age;
        string str,eff_class;
        if(!ob) return "�V�J";
        if( stringp(str = ob->query("rank_info/rude")) )
                return str;
        if(ob->query("race")=="���~") return "�b��";
        if(ob->query("race")=="monster") return "����";
        if(ob->query("race")=="protoss")
                return "��K��";
        if(ob->query("race")=="zerg")
                return "�j����";

        if( ob->query("class2") ) eff_class=ob->query("class2");
        else if( ob->query("class1") ) eff_class=ob->query("class1");
        else if( ob->query("class") ) eff_class=ob->query("class");
        else eff_class="none";

        age = ob->query("age");
        switch(ob->query("gender"))
        {
                case "�k��":
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                        if( age < 20 ) return "����";
                                        if( age < 40 ) return "��H";
                                        if( age < 60 ) return "���k";
                                        if( age < 100 ) return "�ѧ��k";
                                        return "����";
                                        break;
                        }
                        
                default:
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                                if( age < 20 ) return "�V�y";
                                                if( age < 50 ) return "���";
                                                if( age < 80 ) return "�Ѥ���";
                                                return "�ѩǪ�";
                                                break;
                        }
        }
}

string query_self(object ob)
{
        int age;
        string str,eff_class;

        if( stringp(str = ob->query("rank_info/self")) )
                return str;
        if(ob->query("race")=="���~") return "��";
        if( ob->query("class2") ) eff_class=ob->query("class2");
        else if( ob->query("class1") ) eff_class=ob->query("class1");
        else if( ob->query("class") ) eff_class=ob->query("class");
        else eff_class="none";
        
        age = ob->query("age");
        switch(ob->query("gender"))
        {
                case "�k��":
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                                if( age < 30 ) return "�p�f";
                                                else return "�b�U";
                                                break;
                        }
        
                default:
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                                if( age < 50 ) return "�b�U";
                                                else return "���Y�l";
                                                break;
                        }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str,eff_class;

        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;
        if(ob->query("race")=="���~") return "��";
        if( ob->query("class2") ) eff_class=ob->query("class2");
        else if( ob->query("class1") ) eff_class=ob->query("class1");
        else if( ob->query("class") ) eff_class=ob->query("class");
        else eff_class="none";

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "�k��":
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                                if( age < 40 ) return "���h�Q";
                                                else return "�ѮQ";
                                                break;
                        }
                        
                default:
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                                if( age < 50 ) return "���j��";
                                                else return "�Ѥ�";
                                                break;
                        }
        }
}

