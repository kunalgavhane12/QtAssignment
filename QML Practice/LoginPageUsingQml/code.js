function isValidEmail(email) {
    var atIndex = email.indexOf('@');
    if (atIndex === -1)
        return false;

    if (email.left(atIndex) === '')
        return false;

    var domainPart = email.mid(atIndex + 1);
    var domainParts = domainPart.split('.');

    if (domainPart.left(5).localeCompare("gmail", "en", Qt.CaseInsensitive) !== 0
            && domainPart.left(5).localeCompare("yahoo", "en", Qt.CaseInsensitive) !== 0
            && domainPart.left(10).localeCompare("rediffmail", "en", Qt.CaseInsensitive) !== 0)
        return false;

    if (domainParts.length < 2 || domainPart.right(4).localeCompare(".com", "en", Qt.CaseInsensitive) !== 0 && domainPart.right(3).localeCompare(".in", "en", Qt.CaseInsensitive) !== 0)
        return false;

    return true;
}

function isValidPassword(password) {
    var Digit = false;
    var Lowercase = false;
    var Uppercase = false;
    var SpecialChar = false;

    for (var i = 0; i < password.length; ++i)
    {
        var ch = password.charAt(i);

        if (ch.localeCompare(ch.toUpperCase(), "en") === 0 && ch.localeCompare(ch.toLowerCase(), "en") !== 0)
            Uppercase = true;
        else if (ch.localeCompare(ch.toLowerCase(), "en") === 0 && ch.localeCompare(ch.toUpperCase(), "en") !== 0)
            Lowercase = true;
        else if (ch >="0" && ch <= "9")
            Digit = true;
        else if (ch.isPunct() || ch.isSymbol())
            SpecialChar = true;
    }

    return (Digit && Lowercase && Uppercase && SpecialChar && password.length >= 8);
}
