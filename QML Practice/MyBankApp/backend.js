function validateUserCredentials(uname, pword) {

    if(uname === "" || pword === "")
    {
        return 1
    }
    else
    {
        return 0
    }
}

function validateRegisterCredentials(uname, email, pword, pword1){

    if(uname === "" || email === "" || pword === "" || pword1 === "")
    {
        return 1
    }
    else
    {
        return 0
    }
}

function isValidEmail(email) {
    const atIndex = email.indexOf('@');
    if (atIndex === -1)
        return false;

    if (email.substring(0, atIndex).trim().length === 0)
        return false;

    const domainPart = email.substring(atIndex + 1);
    const domainParts = domainPart.split('.');

    if (domainPart.substring(0, 5).localeCompare("gmail", undefined, { sensitivity: 'base' }) !== 0
            && domainPart.substring(0, 7).localeCompare("outlook", undefined, { sensitivity: 'base' }) !== 0
            && domainPart.substring(0, 10).localeCompare("rediffmail", undefined, { sensitivity: 'base' }) !== 0)
        return false;

    if (domainParts.length < 2 || domainPart.substring(domainPart.length - 4).localeCompare(".com", undefined, { sensitivity: 'base' }) !== 0
            && domainPart.substring(domainPart.length - 3).localeCompare(".in", undefined, { sensitivity: 'base' }) !== 0)
        return false;

    return true;
}

function isValidPassword(password) {
    let digit = false;
    let lowercase = false;
    let uppercase = false;
    let specialChar = false;

    for (const ch of password) {
        if (ch.match(/\d/))
            digit = true;
        else if (ch.match(/[a-z]/))
            lowercase = true;
        else if (ch.match(/[A-Z]/))
            uppercase = true;
        else if (ch.match(/[^\w\d]/))
            specialChar = true;
    }

    return (digit && lowercase && uppercase && specialChar && password.length >= 8);
}
