union() {
    // import predefined case and center on screen opening
    translate([3, 0, 0]) import("top.stl", convexity=3);

    // add faceplate
    thickness = 2;

    translate([0, 0, thickness / 2])  difference() {
        cube([140, 40, thickness], center=true); // faceplate
        cube([46.75, 27.5, thickness + 1], center=true); // screen opening
        translate ([47, 0, 0]) cylinder(d=12, h=thickness + 1, center=true); // usb-c charger
        translate ([-47, 0, 0]) cylinder(d=7, h=thickness + 1, center=true); // rotary button
        translate ([-66, -16, 0]) cylinder(d=3, h=thickness + 1, center=true); // screw hole
        translate ([-66, 16, 0]) cylinder(d=3, h=thickness + 1, center=true); // screw hole
        translate ([66, -16, 0]) cylinder(d=3, h=thickness + 1, center=true); // screw hole
        translate ([66, 16, 0]) cylinder(d=3, h=thickness + 1, center=true); // screw hole
    }
}
