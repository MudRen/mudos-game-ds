// gender.c

string gender_self(string sex)
{
    if( !stringp(sex) ) return "�z";
	switch(sex) {
		case "�k��": return "�p";	break;
		default: return "�A";
	}
}

string gender_pronoun(string sex)
{
    if( !stringp(sex) ) return "�z";
	switch(sex) {
		case "���ʯ�":	return "͢";	break;
		case "�k��":	return "�L";	break;
		case "�k��":	return "�o";	break;
		case "����":
		case "�۩�":	return "�e";	break;
		default: return "��";
	}
}

