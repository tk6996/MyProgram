let player = {
    name: "Chutchart Sittipan",
    party: "Pue Tai",
    education: {
        highschool: "Truim Udom",
        bachelor: {
            major: "Engineering",
            university: "MIT"
        },
        doctor: {
            major: "Civil Engineering",
            university: "MIT"
        },
        master: {
            major: "Engineering",
            university: "University of Illinois"
        }
    },
    siblings: [
        "Dr. Prechaya Sittipan",
        "Assoc. Dr. Chanchai Sittipan"
    ]
}
console.log(player.education.bachelor+" " +player.siblings[1]+"\n");